import re

def findSequence(text):
    pattern = '[A-Z][a-z]+'
    
    if re.search(pattern, text):
        return 'Yes'
    else:
        return 'No'

if __name__ == "__main__":
    word = 'geeAkAA55of55gee4ksabc3Ar2x'
    print(findSequence(word))
    word = 'Geeks'
    print(findSequence(word))
    word = 'geeksforgeeks'
    print(findSequence(word))