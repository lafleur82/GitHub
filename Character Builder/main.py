from characters import *

while True:
    print("Would you like to create a character? (y or n)")
    print("Enter exit at any time to quit.")
    user_input = input()

    if user_input == "y":
        print("Enter a name:")
        user_input = input()
        if user_input == "exit":
            break
        else:
            c_name = user_input

        successful = False
        while not successful:
            print("Choose from the following races: (1-5)")
            for k, v in races.items():
                print(k, ":", v)

            user_input = input()
            if user_input == "exit":
                break
            elif int(user_input) in races.keys():
                c_race = races[int(user_input)]
                successful = True
            else:
                print("Not a valid selection.")

        if user_input == "exit":
            break

        successful = False
        while not successful:
            print("Choose from the following classes: (1-5)")
            for k, v in classes.items():
                print(k, ":", v)

            user_input = input()
            if user_input == "exit":
                break
            elif int(user_input) in classes.keys():
                c_class = classes[int(user_input)]
                successful = True
            else:
                print("Not a valid selection.")

        if user_input == "exit":
            break

        newCharacter = Character(c_name, c_race, c_class)

        print("1. Random ability scores, 2. point buy, or 3. manual? (1-3)")
        user_input = input()
        if user_input == "1":
            print("Rolling for ability scores.")
        elif user_input == "2":
            stat = 6
            print("Standard point-buy values are 25 and 32, but the DM may prescribe others.\n")
            print("Each stat begins at 8, but can be lower with DM approval")
            for k, v in point_buy.items():
                if k == 6:
                    print("A stat of", k, "gives", v, "points.")
                elif k == 7:
                    print("A stat of", k, "gives", v, "point.")
                elif k == 9:
                    print("A stat of", k, "costs", v, "point.")
                elif 19 > k > 9:
                    print("A stat of", k, "costs", v, "points.")

            points = 32
            print("Enter ''reset'' to reset point buy, or ''exit'' to quit at any time")
            while points > 0:
                for k in newCharacter.c_ability_scores.keys():
                    print("You have", points, "points remaining.")
                    successful = False
                    while not successful:
                        print("Enter your desired", k, "(8-18)")
                        user_input = input()
                        if user_input == "exit":
                            break
                        elif user_input == "reset":
                            break
                        elif int(user_input) in point_buy.keys():
                            if points + point_buy[int(user_input)] < 0:
                                print("Not enough points.")
                            else:
                                newCharacter.c_ability_scores[k] = user_input
                                points += point_buy[int(user_input)]
                                successful = True
                        else:
                            print("Invalid input")

                    if user_input == "reset" or successful == "exit":
                        break
                if user_input == "exit":
                    break

        elif user_input == "3":
            for k in newCharacter.c_ability_scores.keys():
                print("Enter your", k)
                newCharacter.c_ability_scores[k] = int(input())

        if user_input == "exit":
            break

        newCharacter.print()
    else:
        break
