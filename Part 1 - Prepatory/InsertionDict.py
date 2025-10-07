from collections import OrderedDict

iniordered_dict = OrderedDict([('akshat', '1'), ('nikhil', '2')])

iniordered_dict.update({'manjeet': '3'})
iniordered_dict.move_to_end('manjeet', last=False)

print("Resultant Dictionary : "+str(iniordered_dict))