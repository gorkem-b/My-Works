import requests
def getWords():

    url = "https://www.puzzlers.org/pub/wordlists/unixdict.txt"
    fetchData = requests.get(url)

    wordList = fetchData.content

    wordList = wordList.decode("utf-8").split()

    return wordList


def isOrdered():

    collection = getWords()
    collection = collection[16:]
    word = ''

    for word in collection:
        result = 'Word is ordered'
        i = 0
        l = len(word) - 1

        if (len(word) < 3): 
            continue
        while i < l:         
            if (ord(word[i]) > ord(word[i+1])):
                result = 'Word is not ordered'
                break
            else:
                i += 1
        if (result == 'Word is ordered'):
            print(word,': ',result)


if __name__ == '__main__':
    isOrdered()