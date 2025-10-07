import re

regex = '[a-zA-z0-9]$'
    
def check(string): 
    if(re.search(regex, string)): 
        print("Accept") 
    else: 
        print("Discard") 
    
if __name__ == '__main__' : 
    string = "ankirai@"
    check(string)

    string = "ankitrai326"
    check(string)

    string = "ankit."
    check(string)

    string = "geeksforgeeks"
    check(string)
