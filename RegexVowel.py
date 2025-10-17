import re

regex = '^[aeiouAEIOU][A-Za-z0-9_]*'
    
def check(string): 
    if(re.search(regex, string)): 
        print("Valid") 
    else: 
        print("Invalid") 
    
if __name__ == '__main__' : 
    string = "ankit"
    check(string)

    string = "geeks"
    check(string)

    string = "sandeep"
    check(string)
