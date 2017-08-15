import re

vowels = ['a', 'e', 'i', 'o', 'u']
consonants = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']
alphabet = sorted(vowels + consonants)
my_nums = [1, 2, 3, 4]
my_negative_nums = [-1, -2, -3, -4]
word_list = ["this", "is", "a", "smallish", "sentence"]
a_pangram = "The quick brown fox jumps over the lazy dog."
christmas_words = {"merry": "god", "christmas": "jul", "and": "och", "happy": "gott", "new": "nytt", "year": "år"}
rot13key = {'a': 'n', 'b': 'o', 'c': 'p', 'd': 'q', 'e': 'r', 'f': 's', 'g': 't', 'h': 'u',
            'i': 'v', 'j': 'w', 'k': 'x', 'l': 'y', 'm': 'z', 'n': 'a', 'o': 'b', 'p': 'c',
            'q': 'd', 'r': 'e', 's': 'f', 't': 'g', 'u': 'h', 'v': 'i', 'w': 'j', 'x': 'k',
            'y': 'l', 'z': 'm', 'A': 'N', 'B': 'O', 'C': 'P', 'D': 'Q', 'E': 'R', 'F': 'S',
            'G': 'T', 'H': 'U', 'I': 'V', 'J': 'W', 'K': 'X', 'L': 'Y', 'M': 'Z', 'N': 'A',
            'O': 'B', 'P': 'C', 'Q': 'D', 'R': 'E', 'S': 'F', 'T': 'G', 'U': 'H', 'V': 'I',
            'W': 'J', 'X': 'K', 'Y': 'L', 'Z': 'M'}


def max_func(int1, int2):
    if int1 > int2:
        return int1
    elif int2 > int1:
        return int2
    else:
        return 0

print(max(1, 2))  # expected: 2


def max_of_three(int1, int2, int3):
    if int1 > int2 > int3:
        return int1
    elif int1 < int2 < int3:
        return int3
    else:
        return int2

print(max_of_three(1, 2, 3))  # expected: 3


def str_len(my_str):
    count = 0
    for i in my_str:
        count += 1

    return count

print(str_len("My String"))  # expected: 9


def is_vowel(char):
    if char.lower() in vowels:
        return True
    else:
        return False

print(is_vowel("A"))  # expected: True
print(is_vowel("R"))  # expected: False


def translate(my_str):
    new_str = ""

    for c in my_str:
        if c not in vowels and c is not " ":
            new_str += c + "o" + c
        else:
            new_str += c

    return new_str

print(translate("My string"))


def sum_func(nums):
    num = 0

    for i in nums:
        num += i

    return num


def multiply(nums):
    num = 1

    for i in nums:
        num *= i

    return num

print(sum_func(my_nums))
print(multiply(my_nums))


def reverse(my_str):
    new_str = my_str[::-1]
    return new_str

print(reverse("My string"))


def is_palindrome(my_str):
    my_str = my_str.lower()
    if my_str == my_str[::-1]:
        return True
    else:
        return False

print(is_palindrome("Racecar"))
print(is_palindrome("string"))


def is_member(value, values):
    if value in values:
        return True
    else:
        return False

print(is_member('a', vowels))
print(is_member('b', vowels))


def overlapping(list1, list2):
    for i in list1:
        for j in list2:
            if i == j:
                return True
    return False

print(overlapping(consonants, vowels))
print(overlapping(alphabet, vowels))


def gen_n_chars(n, c):
    chars = ""
    for i in range(n):
        chars += c
    return chars

print(gen_n_chars(5, 'x'))


def histogram(nums):
    for i in nums:
        print(gen_n_chars(i, '*'))

histogram(my_nums)


def max_in_list(nums):
    max_num = nums[0]
    for i in nums:
        if i > max_num:
            max_num = i
    return max_num

print(max_in_list(my_nums))
print(max_in_list(my_negative_nums))


def chars_in_words(sentence):
    counts = []
    for words in sentence:
        count = 0
        for i in words:
            count += 1
        counts.append(count)
    return counts

print(chars_in_words(word_list))


def longest_word(sentence):
    return max_in_list(chars_in_words(sentence))

print(longest_word(word_list))


def filter_long_words(sentence, max_len):
    long_words = []
    for words in sentence:
        if len(words) > max_len:
            long_words.append(words)
    return long_words

print(filter_long_words(word_list, 5))


def is_palindrome_phrase(sentence):
    new_str = ''.join(sentence.split())
    if is_palindrome(new_str):
        return True
    else:
        return False

print(is_palindrome_phrase("Step on no pets"))
print(is_palindrome_phrase("Not a palindrome"))


def is_pangram(sentence):
    letters = ""

    for letter in sentence:
        if letter.lower() not in letters and str.isalpha(letter):
            letters += letter.lower()

    if len(letters) == 26:
        return True
    else:
        return False

print(is_pangram(word_list))
print(is_pangram(a_pangram))


def bottles_of_beer(bottles):
    if bottles > 0:
        print(str(bottles) + " bottles of beer on the wall, " + str(bottles) + " bottles of beer.")
        bottles -= 1
        print("Take one down, pass it around, " + str(bottles) + " bottles of beer on the wall.\n")
        bottles_of_beer(bottles)
    else:
        return 0

#bottles_of_beer(99)


def translate_to_swedish(sentence):
    translation = []

    for word in sentence.split():
        translation.append(christmas_words[word.lower()])

    return translation

print(translate_to_swedish("Merry Christmas"))


def char_freq(my_str):
    freq = {}

    for char in my_str:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1

    return freq

print(char_freq("abbabcbdbabdbdbabababcbcbab"))  # 7a, 14b, 3c, 3d


def caesar_cypher(my_str):
    new_str = ""

    for char in my_str:
        if char in rot13key:
            new_str += rot13key[char]
        else:
            new_str += char

    return new_str

print(caesar_cypher("Pnrfne pvcure? V zhpu cersre Pnrfne fnynq!"))
print(caesar_cypher("Rotate this string."))


def correct(sentence):
    new_sentence = ""
    

    return new_sentence

correct("This   is  very funny  and    cool.Indeed!")
