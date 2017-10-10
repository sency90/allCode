n, m = map(int,input().split())
A = [list(map(int,input().split())) for i in range(n)]
m, k = map(int,input().split())
B = [list(map(int,input().split())) for i in range(m)]
AB = [[0]*k for i in range(n)]

for i in range(n):
    for j in range(k):
        AB[i][j] = sum(A[i][q]*B[q][j] for q in range(m))
for row in AB:
    print(' '.join(map(str,row)))
