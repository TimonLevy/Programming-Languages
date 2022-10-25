//	Client.c
//	Programmer:	Daniel L.

//	This program sends both given arguments to a socket on a harcoded IP and PORT.
//	* Pairs with the Server program.

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<WinSock2.h>
#include	<ws2tcpip.h>

#define		SUCCESS			1
#define		FAILURE			0
#define		BUFFLEN			16

#define		IP				"127.0.0.1"
#define		PORT			6666
#pragma 	comment(lib, "Ws2_32.lib")

typedef	struct attack {
	char* victim;
	char* attacker;
} attack;

struct sockaddr_in clntAddr;
WSADATA ws;


int main(int argc, char *argv[])
{

	// Initialize the windows socketing API.
	if ((WSAStartup(MAKEWORD(2, 2), &ws)) != 0)
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
	clntAddr.sin_family = AF_INET;
	clntAddr.sin_port = htons(PORT);
	clntAddr.sin_addr.s_addr = inet_addr(IP);
	memset(clntAddr.sin_zero, 0, 8);
	
	// Connect to the server.
	if ((connect(newSocket, (struct sockaddr*)&clntAddr, sizeof(struct sockaddr)) == SOCKET_ERROR))
	{
		printf("[-] Socket failed to connect.\n");
		WSACleanup();
		return FAILURE;
	}
	else
	{
		printf("[+] Socket connected to server successfuly.\n");
	}
	
	// Delay to let the server ready the socket for reading.
	Sleep(500);

	// Send both first and second arguments.
	send(newSocket, argv[1], strlen(argv[1]), 0);
	send(newSocket, argv[2], strlen(argv[2]), 0);
}