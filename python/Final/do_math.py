import random


def do_math():
    """Using the random module, create a program that, first, generates two positive one-digit numbers and then displays
    a question to the user incorporating those numbers, e.g. “What is the sum of x and y?”. Ensure your program conducts 
    error-checking on the answer and notifies the user whether the answer is correct or not."""

    a = random.randint(1, 9)
    b = random.randint(1, 9)
    op = random.randint(1, 3)
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

    user_input = float(input())

    if user_input == answer:
        print("Correct!")
    else:
        print("Incorrect.")

if __name__ == '__main__':
    while True:
        do_math()
        print("Another? (y/n)")
        user_input = input()
        if user_input != 'y':
            break

