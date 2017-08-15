import random

#pirate bartender
questions = {
    "strong": "Do ye like yer drinks strong? ",
    "salty": "Do ye like it with a salty tang? ",
    "bitter": "Are ye a lubber who likes it bitter? ",
    "sweet": "Would ye like a bit of sweetness with yer poison? ",
    "fruity": "Are ye one for a fruity finish? "
}

ingredients = {
    "strong": ["glug of rum", "slug of whiskey", "splash of gin"],
    "salty": ["olive on a stick", "salt-dusted rim", "rasher of bacon"],
    "bitter": ["shake of bitters", "splash of tonic", "twist of lemon peel"],
    "sweet": ["sugar cube", "spoonful of honey", "splash of cola"],
    "fruity": ["slice of orange", "dash of cassis", "cherry on top"]
}


def which_drink(flavors):
    answers = {}
    for k in flavors:
        answer = str(input(flavors[k]))

        if answer == "yes" or answer == "y":
            answers[k] = True
        elif answer == "no" or answer == "n":
            answers[k] = False
        else:
            print("Yes/y or No/n required.")

        print("\n")

    return answers


def make_drink(flavors):
    drink = ""
    for i, k in enumerate(flavors):
        if flavors[k] is True:
            drink += random.choice(ingredients[k]) + ", "

    drink = drink[:-2]  #remove trailing comma

    return drink

while True:
    print(make_drink(which_drink(questions)))
    if str(input("Another? (yar or nay): ")) != 'yar':
        break
