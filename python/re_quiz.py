"""Create a program that will load and execute the exported function (source of your program)"""

import ctypes
import os

c = ctypes.CDLL("C:\Users\DOTlaptop\Desktop\\re_quiz\\re_lab4.1_x86.dll")
myFile = "C:\Users\DOTlaptop\Desktop\\re_quiz\\badlove.dat"
file_size = os.stat(myFile).st_size
print file_size

c[1](file_size, myFile)
