# DirectoRecursivenessssss.py
# 
# Programmer    : Daniel L.
# Personal No.  : 9127567
# Date          : 25.8.22
# ===========================
# This program prints A directories children in a tree.

"""
* Great program!
* Your program doesn't run.
"""


# Modules
import os

# Constants
INDENT  = "--- "

def treeDir(path, depth = 0):

    # Check if the given path is a directory.
    if not os.path.isdir(path):
        print("[ERROR] Given path is not a directory.")
        return

    # Get Directory children.
    children = os.listdir(path)
    
    for entity in children:

        # Print item with identation.
        print(f"{INDENT * depth}{entity}")

        # If item is directory print all children and repeat.
        if os.path.isdir(os.path.join(path, entity)):
            treeDir(os.path.join(path, entity), depth + 1)
            
            

def main():
    pass

if __name__ == "__main__":
    main()
