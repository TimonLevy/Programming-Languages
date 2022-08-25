# RemoteCMD.py
#
# Programmer    : Daniel L.
# Personal NO.  : 9127567
# Date          : 08.24.22
# =========================== #
# This program open a socket  on the computer to, recieves cmd commands
# and returns the output.
# =========================== #

# Modules
import socket
import subprocess as sub

# Constants
PORT        = 7567
BUFFER      = 9999
IP          = 0
EXITCOMM    = "exit"
PROMPT      = "\n | remoteShell@{} # "

def main():

    # Create socket and bind it to the local address.
    bind_addr = ('', PORT)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(bind_addr)
    sock.listen()

    # Get the first connection
    conn, addr = sock.accept()

    # Send format string.
    conn.send(PROMPT.format(addr[IP]).encode())
    
    # Get the command from the remote connected machine.
    command = conn.recv(BUFFER).decode().strip()

    # Keep processing command until 'exit' command is recieved.
    while command.lower() != EXITCOMM:
        
        # Run recieved command in the shell and process output.
        output = sub.run(command,  capture_output = True, shell = True)
        output = output.stdout if output.stdout else output.stderr
        
        # Send the command output.
        conn.send(output)
        
        # Get the next command.
        conn.send(PROMPT.format(addr[IP]).encode())
        command = conn.recv(BUFFER).decode()

    # Close the connection and socket when the exit command is recieved.
    sock.close()
        

if __name__ == "__main__":
    main()
