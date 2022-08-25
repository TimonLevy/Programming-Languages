# RunningMouse.py
# 
# Programmer    : Daniel L.
# Personal No.  : 9127567
# Date          : 25.08.22
# =========================
# This programs moves the mouse randomly.

# Modules
import win32api
import random
import math
import time

# Constants
SM_CXVIRTUALSCREEN  = 78
SM_CYVIRTUALSCREEN  = 79
REPEATTIME          = 10

def main():

    # Get effective screen size.
    xScreenSize = win32api.GetSystemMetrics(SM_CXVIRTUALSCREEN)
    yScreenSize = win32api.GetSystemMetrics(SM_CYVIRTUALSCREEN)

    while True:

        # Generate random coords.
        xRandom = math.floor(random.uniform(0, xScreenSize))
        yRandom = math.floor(random.uniform(0, yScreenSize))

        # Move cursor.
        win32api.SetCursorPos((xRandom, yRandom))

        # Wait 10 seconds.
        time.sleep(REPEATTIME)
        

if __name__ == "__main__":
    main()
