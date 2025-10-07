test_list = [('Gfg', 3), ('best', 9), ('CS', 10), ('Geeks', 2)]

print("The original list is : " + str(test_list))

ord_list = ['Geeks', 'best', 'CS', 'Gfg']

temp = dict(test_list)
res = [(key, temp[key]) for key in ord_list]
    
print("The ordered tuple list : " + str(res))