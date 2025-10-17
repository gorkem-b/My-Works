a = [1, 2, 3]  
b = (4, 5)     
c = [6, 7]     

a.extend(b) 
print(a)

d = b + tuple(c)
print(d)