# DirectoRecursivenessssss.py
# 
# Programmer    : Daniel L.
# Personal No.  : 9127567
# Date          : 25.8.22
# ===========================
# This program prints A directories children in a tree.

# Modules
import os

# Constants
INDENT  = "└──"

def treeDir(path, depth = 0):

    # Check if the given path is a directory.
    if not os.path.isdir(path):
        print("[ERROR] Given path is not a directory.")
        return

    children = os.listdir(path)
    
    for entity in children:
        print(f"{INDENT * depth}{entity}")
        
        if os.path.isdir(os.path.join(path, entity)):
            treeDir(os.path.join(path, entity), depth + 1)
            
            

def main():
    treeDir(r"C:\Users\Matrix\Desktop\TestDir")

if __name__ == "__main__":
    main()
