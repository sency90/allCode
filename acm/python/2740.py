# input Sector

# First matrix
N, M = map(int, input().split())
l1=[[0 for value in range(M)] for value in range(N)]
for i in range(N):
    l1[i]=list(map(int, input().split()))

# Second matrix
Second_M, K = map(int, input().split())
l2=[[0 for value in range(K)] for value in range(Second_M)]
for i in range(Second_M):
    l2[i]=list(map(int, input().split()))

# Initiate result matrix
result=[[0 for value in range(K)] for value in range(N)]

# Multifly matrix
# iterate through rows of X
for i in range(len(l1)):
   # iterate through columns of Y
   for j in range(len(l2[0])):
       # iterate through rows of Y
       for k in range(len(l2)):
           result[i][j] += l1[i][k] * l2[k][j]

# print result matrix
for i in range(N):
    for j in range(K):
        print(result[i][j], end=' ')
    print('')


