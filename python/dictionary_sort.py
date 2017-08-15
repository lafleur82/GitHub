from collections import OrderedDict
from operator import itemgetter


def dict_sort(my_dict, up_or_down):
    new_dict = OrderedDict(sorted(my_dict.items(), key=itemgetter(1), reverse=up_or_down))

    return new_dict


dict1 = {1: 3, 2: 5, 3: 4, 4: 7}

print(dict_sort(dict1, False))
print("\n")
print(dict_sort(dict1, True))
print("\n")
