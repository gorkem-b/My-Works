def find_words_with_three_chars(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
        words = content.split()

        words_with_three_chars = [word for word in words if len(word) == 3]

        return words_with_three_chars

file_name = "File1.txt"
result = find_words_with_three_chars(file_name)

print("Words containing three characters:")
print(result)