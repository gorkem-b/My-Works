import pickle


try:
    geeky_file = open('GFG.txt', 'r')
    dictionary_list = pickle.load(geeky_file)
    
    for d in dictionary_list:
        print(d)
    geeky_file.close()

except:
    print("Something unexpected occurred!")