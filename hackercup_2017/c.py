from ctypes import *
import re
import sys

def freopen(f, option, stream):
    import os
    oldf = open(f,option)
    oldfd = oldf.fileno()
    newfd = stream.fileno()
    os.close(newfd)
    os.dup2(oldfd, newfd)

freopen("./input.txt", "r", sys.stdin)
freopen("./output.txt", "w", sys.stdout)
d = [[[-1]*20001 for i in range(21)] for j in range(21)]
po = [[0]*21 for i in range(21)]

def f(x,y,p):
    if p<0: return f(x,y,0)
    if d[x][y][p]>=0: return d[x][y][p]
    else: d[x][y][p]=0

    if x==0:
        if p==0: d[x][y][p]=1
        else: d[x][y][p]=0
        return d[x][y][p]

    for i in range(1,y+1):
        d[x][y][p] += f(x-1,y,p-i)

    return d[x][y][p]

def spow(y,x):
    if po[y][x]>0: return po[y][x]
    if x==0:
        po[y][x]=1
        return po[y][x]

    po[y][x] = spow(y,x>>1)
    po[y][x] *= po[y][x]
    if x%2==0: return po[y][x]
    else:
        po[y][x] *= y
        return po[y][x]

tc = int(input())
for t in range(tc):
    h,s = input().split()
    h=int(h)
    s=int(s)
    ans = 0.0

    x,y,z=(0,0,0)
    pat1 = re.compile("(\d+)[d](\d+)([+\-]\d+)")
    pat2 = re.compile("(\d+)[d](\d+)")
    for word in input().split(" "):
        z=0
        if pat1.match(word):
            x,y,z=pat1.match(word).groups()
        else:
            x,y=pat2.match(word).groups()
        x=int(x)
        y=int(y)
        z=int(z)
        ans = max(ans, float(f(x,y,h-z))/float(spow(y,x)))

    print("Case #%d: %.6lf"%(t+1, ans))
