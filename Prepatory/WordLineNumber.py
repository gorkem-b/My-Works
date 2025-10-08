def find_word_line_number(filename, target_word):
    line_number = 0

    with open(filename, 'r') as file:
        for line in file:
            line_number += 1
            if target_word in line:
                return line_number

    return None

filename = "File1.txt"
word_to_find = "hello"
line_number = find_word_line_number(filename, word_to_find)
if line_number is not None:
    print(f"The word '{word_to_find}' is present in line number: {line_number}")
else:
    print(f"The word '{word_to_find}' is not found in the file.")
