class Bicycle:
    def __init__(self, m, w, c):
        self.model = m
        self.weight = w
        self.cost = c

    def set_model(self, m):
        self.model = m

    def set_weight(self, w):
        self.weight = w

    def set_cost(self, c):
        self.cost = c


class Customer:
    def __init__(self, n, b):
        self.name = n
        self.budget = b
        self.inventory = []

    def set_name(self, n):
        self.name = n

    def set_budget(self, b):
        self.budget = b

    def buy_bike(self, bike, cost):
        self.budget -= cost
        self.inventory.append(bike)

    def print_inventory(self):
        print(self.name + ":")
        print("Model", "\t\t\t", "Weight")

        for bike in self.inventory:
            print(bike.model, "\t\t\t", bike.weight)

    def print_budget(self):
        print(self.budget)


class BikeShop:
    def __init__(self, name):
        self.name = name
        self.profits = 0
        self.uid = 0
        self.inventory = {}
        self.markup = .2

    def set_name(self, value):
        self.name = value

    def sell_bike(self, item_num, buyer):
        self.profits += (self.inventory[item_num].cost * self.markup)
        buyer.buy_bike(self.inventory[item_num], self.inventory[item_num].cost * (1 + self.markup))
        del self.inventory[item_num]

    def add_bike(self, m, w, c):
        self.uid += 1
        item_num = self.uid
        self.inventory[item_num] = Bicycle(m, w, c)

    def print_inventory(self):
        print(self.name + ":")
        print("Item ID", "\t", "Model", "\t\t\t", "Weight", "\t", "Cost")

        for num, bikes in self.inventory.items():

            if len(bikes.model) > 9:
                print(num, "\t\t\t",  bikes.model, "\t", bikes.weight, "\t\t", bikes.cost * (1 + self.markup))
            elif len(bikes.model) > 5:
                print(num, "\t\t\t",  bikes.model, "\t\t", bikes.weight, "\t\t", bikes.cost * (1 + self.markup))
            else:
                if bikes.weight < 10:
                    print(num, "\t\t\t",  bikes.model, "\t\t\t", bikes.weight, "\t\t\t", bikes.cost * (1 + self.markup))
                else:
                    print(num, "\t\t\t",  bikes.model, "\t\t\t", bikes.weight, "\t\t", bikes.cost * (1 + self.markup))
        print("\n")

    def show_profits(self):
        print("Current profits: $" + str(self.profits) + "\n")


customer1 = Customer("Joel", 1000)
customer2 = Customer("Leslie", 500)
customer3 = Customer("David", 200)

bike_shop = BikeShop("Bikes-R-Us")

bike_shop.add_bike("Diamondback", 35, 250)
bike_shop.add_bike("Huffy", 30, 125)
bike_shop.add_bike("Razor", 5, 75)
bike_shop.add_bike("Iverson", 15, 450)
bike_shop.add_bike("Murray", 20, 325)
bike_shop.add_bike("Roadmaster", 10, 675)


bike_shop.print_inventory()

bike_shop.sell_bike(2, customer1)

bike_shop.print_inventory()
bike_shop.show_profits()

customer1.print_inventory()
customer1.print_budget()
