import re

pat1 = re.compile("(\d+)[d](\d+)([+|-]\d+)")
pat2 = re.compile("(\d+)[d](\d+)")
for word in input().split(" "):
    x,y,z=(0,0,0)
    if pat1.match(word):
        x,y,z=pat1.match(word).groups()
    else:
        x,y=pat2.match(word).groups()

    print(x,y,z)
