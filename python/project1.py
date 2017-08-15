#hello world
x = "hello world"
print(x)


#error handling
try:
    num1 = 5 #float(input("Enter the numerator: "))
    num2 = 5 #float(input("Enter the denominator: "))
    result = num1/num2
except ValueError:
    print("Two numbers are required.")
except ZeroDivisionError:
    print("Denominator can't be a zero.")
else:
    print(num1, "/", num2, "=", result)


#functions
def square(x):
    return x * x

for y in range(1, 11):
    print (square(y))


#fizzbuzz
maxFizzBuzz = 16 #int(input("Enter max number")) + 1

for y in range(1, maxFizzBuzz):
    if y % 3 == 0 and y % 5 == 0:
        print("fizzbuzz" + "\n")
    elif y % 3 == 0:
        print("fizz" + "\n")
    elif y % 5 == 0:
        print("buzz" + "\n")
    else:
        print(str(y) + "\n")


#lists
myList = list(range(1, 10))
print("Max is " + str(max(myList)) + "\n")


#more lists
count = 0
theList = ['abc', 'xyz', 'aba', '1221']

for i in theList:
    if len(i) > 2 and i[0] == i[-1]:
        count += 1

print("The count is " + str(count) + "\n")


#even more lists!
def is_contained(list1, list2):
    for i in list1:
        for j in list2:
            if i == j:
                return True
    return False


firstList = [1, 2, 3]
secondList = [3, 4, 5]
print(is_contained(firstList, secondList))

