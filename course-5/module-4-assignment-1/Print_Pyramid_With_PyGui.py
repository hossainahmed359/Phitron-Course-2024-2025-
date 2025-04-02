# Problem - 5
# Take a number from the user and draw a pyramid using PyAutoGUI

import pyautogui
from time import sleep

n = int(input())

sleep(3)

for i in range(n):
    for j in range(i + 1):
        pyautogui.write("#")
    pyautogui.write("\n")

