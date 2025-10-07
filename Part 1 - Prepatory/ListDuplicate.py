test_str = 'Gfg is best . Gfg also has Classes now. Classes help understand better . '

print("The original string is : " + str(test_str)) 

repl_dict = {'Gfg' : 'It', 'Classes' : 'They' } 

 
test_list = test_str.split(' ') 
res = ' '.join([repl_dict.get(val) if val in repl_dict.keys() and test_list.index(val) != idx 
                                else val for idx, val in enumerate(test_list)]) 

print("The string after replacing : " + str(res))