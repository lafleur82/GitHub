from math import *


def solve_circle(r):
    """Write a program to request a radius value from the user then calculate and print out the diameter, circumference, 
    and area of a circle with that radius. Use the math module to import the value of π."""

    if type(r) is int:
        diameter = 2 * r
        circumference = 2 * pi * r
        area = pi * r * r

        answer = {"diameter": diameter, "circumference": circumference, "area": area}
        return answer
    else:
        return "NAN"


if __name__ == '__main__':
    radius = 4
    print(solve_circle(radius))
