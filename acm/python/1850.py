def gcd(b,s):
    if s==0: return int(b)
    else: return gcd(s,b%s)

a,b = map(int, input().split())
g = gcd(a,b)
i = 0
for i in range(g): print(1, end='')
