# InternetSpiderMan.py
# |
# Programmer    : Daniel L.
# Personal No.  :   9127567
# Date          : 13.9.2022
# _________________________
# This is a webcrawler. it get a file of extenstions
# and searches for them in a website.

# Imports
import argparse as arp
import requests


def main():

    # Add arguments to the program.
    parser = arp.ArgumentParser(prog="WebCrawler")

    parser.add_argument(dest = "file",\
                        type = str,\
                        help = "The path to the file containing the list of extensions.")
    parser.add_argument(dest = "target",\
                        type = str,\
                        help = "The target url to perform the attack on. Example: www.google.com")
    
    args = parser.parse_args()

    # Send request for each extension.
    for extension in open(args.file).readlines():
        resp = requests.get(f"https://{args.target}/{extension.strip()}")

        # If response code is below 400 prompt user.
        if resp.ok:
            print(f"got [{args.target}/{extension.strip()}]")
    

if __name__ == "__main__":
    main()
