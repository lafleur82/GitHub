"""Using OOP principles, create a Rectangle class that can calculate the perimeter and area measurements when length 
and width are input. A set method should be included to verify that the input values are floating-point numbers. """


class Rectangle:
    def __init__(self, top_left=(0, 0), bottom_right=(0, 0), length=0, width=0):
        """class can accept either the length and width as direct input or 
        accept only the coordinates of the top left and bottom right corners as tuples."""

        self.top_left = top_left
        self.bottom_right = bottom_right
        if length == 0:
            self.length = self.get_length()
        else:
            self.length = length
        if width == 0:
            self.width = self.get_width()
        else:
            self.width = width

    def get_length(self):
        """calculate the length of a rectangle given top left and bottom right coordinate tuples"""
        x1, y1 = self.top_left
        x2, y2 = self.bottom_right
        return abs(x1) + abs(x2)

    def get_width(self):
        """calculate the width of a rectangle given top left and bottom right coordinate tuples"""
        x1, y1 = self.top_left
        x2, y2 = self.bottom_right
        return abs(y1) + abs(y2)

    def get_perimeter(self):
        """calculate the perimeter given the length and width of the rectangle"""
        return self.length * 2 + self.width * 2

    def get_area(self):
        """calculate the area given the length and width of the rectangle"""
        return self.length * self.width

    def is_square(self):
        """determine whether the rectangle meets the criteria for being a square."""
        if self.length == self.width:
            return True
        else:
            return False

if __name__ == '__main__':
    l = 4
    w = 2
    myRectangle = Rectangle(length=l, width=w)
    print(myRectangle.get_area())
    print(myRectangle.get_perimeter())
    print(myRectangle.is_square())

    l = 4
    w = 4
    myRectangle = Rectangle(length=l, width=w)
    print(myRectangle.get_area())
    print(myRectangle.get_perimeter())
    print(myRectangle.is_square())

    tlc = (-2, 4)
    brc = (2, -4)
    myRectangle = Rectangle(tlc, brc)
    print(myRectangle.get_area())
    print(myRectangle.get_perimeter())
    print(myRectangle.is_square())

    tlc = (-2, 2)
    brc = (2, -2)
    myRectangle = Rectangle(tlc, brc)
    print(myRectangle.get_area())
    print(myRectangle.get_perimeter())
    print(myRectangle.is_square())

    help(Rectangle)
