import math

print("loops and data-types")
data_list = [1452, 11.23, 1+2j, True, 'w3resource', (0, -1), [5, 12], {"class": 'V', "section": 'A'}]

for i in data_list:
    print(i, type(i))

print("\nFactorials")
n = 5
print("Factorial of", n, "is", math.factorial(n))


print("\nCount strings")


def count_letters(the_string, upper_or_lower=""):
    upper = 0
    lower = 0
    for l in the_string:
        if l.isupper():
            upper += 1
        elif l.islower():
            lower += 1

    if upper_or_lower == "upper":
        return upper
    elif upper_or_lower == "lower":
        return lower

my_str = "\"This string has letters\""
print(my_str, "is the string.")
print("Upper letters:", count_letters(my_str, "upper"))
print("Lower letters:", count_letters(my_str, "lower"))
