file1 = open('input.txt', 'r')
file2 = open('output.txt', 'w')

for line in file1.readlines():
    if not (line.startswith('TextGenerator')):
        print(line)
        file2.write(line)

file2.close()
file1.close()
