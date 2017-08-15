import random


def has_duplicates(the_list):
    """Using lists, read in 30 numbers and print out whether the number read is a duplicate of a previous number."""

    previous = []
    for i in the_list:
        if i in previous:
            print(i, "is a duplicate")
        else:
            print(i)
            previous.append(i)


if __name__ == '__main__':
    my_list = [random.randint(1, 100) for k in range(30)]
    has_duplicates(my_list)
