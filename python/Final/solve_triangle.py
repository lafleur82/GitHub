from math import sqrt


def solve_triangle(side_a, side_b):
    """The Pythagorean equation for a right triangle is a^2 + b^2 = c^2 , where c is the hypotenuse while a and b 
    are the remaining sides. Calculate all values for right triangles when the sides are no greater than 20."""

    if side_a < 20 and side_b < 20:
        side_c = sqrt(side_a * side_a + side_b * side_b)
        return side_c
    else:
        return False


if __name__ == '__main__':
    print(solve_triangle(6, 5))
    print(solve_triangle(21, 20))  # should return false
