a=input().split()
i=0
for x in range(3):
    a[i]=int(a[i])
    i+=1

print((a[0]+a[1])%a[2])
print((a[0]%a[2] + a[1]%a[2])%a[2])
print((a[0]*a[1])%a[2])
print((a[0]%a[2] * (a[1]%a[2]))%a[2])
