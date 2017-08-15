from ctypes import *
from ctypes.util import find_library

libc = CDLL(find_library('c'))
myString = create_string_buffer("Hello world", 50)
string2 = create_string_buffer("", 50)

# printf w/ format specifiers
printf = libc.printf
printf.argtypes = [c_char_p]
printf("%s\n", myString)

# strlen
strlen = libc.strlen
strlen.argtypes = [c_char_p]
printf("strlen(myString) returns: %d\n", strlen(myString))

# strstr, user printf to print the found string
strstr = libc.strstr
strstr.argtypes = [c_char_p]
printf("strstr(w) return: %s\n", strstr(myString, "w"))

# strcpy
strcpy = libc.strcpy
strcpy.argtypes = [c_char_p]
strcpy(string2, myString)
printf("String2 contains: %s\n", string2)

# strcat
strcat = libc.strcat
strcat.argtypes = [c_char_p]
printf("strcat(myString, string2 returns: %s\n", strcat(myString, string2))

# sprintf
sprintf = libc.sprintf
sprintf.argtypes = [c_char_p]
a = create_string_buffer("", 100)
e = sprintf(a, "%s", strcat(myString, string2))
printf("[%s] is %d chars long\n", a, e)

# memset
memset = libc.memset
memset.argtypes = [c_char_p, c_void_p, c_int]
memset(myString, 42, 5)
printf("%s\n", myString)

# memmove
memmove = libc.memmove
memmove.argtypes = [c_void_p, c_void_p, c_int]
newString = create_string_buffer("memmove can be very useful......", 33)
printf("New string: %s\n", newString)
memmove(byref(newString, 20), byref(newString, 15), 11)
printf("Moved new string: %s\n", newString)

# atoi
atoi = libc.atoi
atoi.restype = c_int
numString = create_string_buffer("12345", 5)
atoi.argtypes = [c_void_p]
printf("%d\n", atoi(numString))
