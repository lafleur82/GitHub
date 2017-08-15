from math import *
import random


def solve_sas_triangle(b, c, angle_a, test=False):
    """Given two sides and an angle between them find the length of the third side and the remaining angles"""
    angle_a = radians(angle_a)
    b2 = b * b
    c2 = c * c
    a = sqrt(b2 + c2 - (2*b*c * cos(angle_a)))
    angle_b = degrees(asin((sin(angle_a)*b)/a))
    angle_c = 180 - degrees(angle_a) - angle_b

    if test:
        print("a2 = b2 + c2 − 2bc*cosA")
        print("b=", b)
        print("c=", c)
        print("A=", degrees(angle_a))
        print("B=", degrees(angle_b))
        print("C=", angle_c)
        print("cos(A)=", cos(radians(angle_a)))
        print("b^2 =", b2)
        print("c^2 =", c2)

    saa = {"Side A": a, "Angle B": angle_b, "Angle C": angle_c}
    return saa


help(solve_sas_triangle)
print(solve_sas_triangle(5, 7, 49))


def flashcards():
    """Generates two numbers, asks the user to provide an answer to a math question using those numbers, 
    and then verifies the answer"""

    a = random.randint(0, 9)
    b = random.randint(0, 9)
    op = random.randint(1, 4)
    answer = 0

    if op == 1:
        print("What is", a, "+", b, "?")
        answer = a + b
    elif op == 2:
        print("What is", a, "-", b, "?")
        answer = a - b
    elif op == 3:
        print("What is", a, "*", b, "?")
        answer = a * b
    elif op == 4:
        print("What is", a, "/", b, "?")
        answer = a / b
        print(a/b)

    user_input = float(input())

    if user_input == answer:
        print("Correct!")
    else:
        print("Incorrect.")
'''
while True:
    flashcards()
    print("Another? (y/n)")
    user_input = input()
    if user_input != 'y':
        break
'''


def tuple_has_duplicates(my_tuple):
    """Create a tuple of 50 random numbers and a) determine if there are any duplicate values 
    and b) display the duplicate numbers."""

    duplicates = []
    for i in my_tuple:
        if my_tuple.count(i) > 1 and i not in duplicates:
            duplicates.append(i)
        counter = 0
        # for k in my_tuple:
        #     if i == k:
        #         counter += 1
        #     if counter > 1 and i not in duplicates:
        #         duplicates.append(i)
    if duplicates:
        return duplicates
    else:
        return False


myTuple = [random.randint(1, 100) for k in range(50)]
print(tuple_has_duplicates(myTuple))

# sample won't have duplicates
myTuple = [random.sample(range(1, 100), 50)]
print(tuple_has_duplicates(myTuple))


def solve_circle(radius):
    """Create a class Circle that can calculate the diameter, circumference, and area when a radius is input. 
    A constructor method should confirm that the input radius is a valid number."""

    if type(radius) is int:
        diameter = 2 * radius
        circumference = 2 * pi * radius
        area = pi * radius * radius

        answer = {"diameter": diameter, "circumference": circumference, "area": area}
        return answer
    else:
        return "NAN"

print(solve_circle(2))
print(solve_circle("Five"))
