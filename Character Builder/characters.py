races = {1: "Human", 2: "Elf", 3: "Dwarf", 4: "Halfling", 5: "Half-Elf"}
classes = {1: "Fighter", 2: "Rogue", 3: "Cleric", 4: "Wizard", 5: "Bard"}
point_buy = {6: 2, 7: 1, 8: 0, 9: -1, 10: -2, 11: -3, 12: -4, 13: -5, 14: -6, 15: -8, 16: -10, 17: -13, 18: -16}


class Character:
    def __init__(self, c_name, c_race, c_class, c_ability_scores={"strength": 10, "dexterity": 10, "constitution": 10,
                                             "intelligence": 10, "wisdom": 10, "charisma": 10}):
        self.c_ability_scores = {}
        for k, v in c_ability_scores.items():
            self.c_ability_scores[k] = v

        self.c_name = c_name
        self.c_race = c_race
        self.c_class = c_class
        self.c_feats = []

    def change_stat(self, c_ability, c_score):
        self.c_ability_scores[c_ability] = c_score

    def change_name(self, c_name):
        self.c_name = c_name

    def print(self):
        print("\n")
        print(self.c_name)
        print(self.c_race, "-", self.c_class)

        for k, v in self.c_ability_scores.items():
            print(k, "-", v)
