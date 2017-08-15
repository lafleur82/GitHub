student_data = {
    'id1': {
            'name': ['Sara'],
            'class': ['V'],
            'subject': ['english, math, science']
        },
    'id2': {
            'name': ['David'],
            'class': ['V'],
            'subject': ['english, math, science']
        },
    'id3': {
            'name': ['Sara'],
            'class': ['V'],
            'subject': ['english, math, science']
        },
    'id4': {
            'name': ['Surya'],
            'class': ['V'],
            'subject': ['english, math, science']
        }
}


def make_unique(my_dict):
    new_dict = {}
    for k, v in my_dict.items():
        if v not in new_dict.values():
            new_dict[k] = v
    return new_dict

print(make_unique(student_data))
