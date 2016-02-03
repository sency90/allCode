import math
n, m = raw_input().split()
n = int(n)
m = int(m)
res = math.factorial(n)//math.factorial(n-m)//math.factorial(m)
print("%d" % res)
