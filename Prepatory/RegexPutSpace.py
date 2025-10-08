import re

def putSpace(text):
    words = re.findall('[A-Z][a-z]*', text)

    for i in range(0, len(words)):
        words[i] = words[i][0].lower() + words[i][1:]
    print(' '.join(words))

if __name__ == "__main__":
    text = 'BruceWayneIsBatman'
    putSpace(text)