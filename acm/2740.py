# input Sector

# First matrix
N, M = map(int, input().split())
l1=[list(map(int, input().split())) for value in range(N)]

# Second matrix
M, K = map(int, input().split())
l2=[list(map(int, input().split())) for value in range(Second_M)]

# Initiate result matrix
result=[[0 for value in range(N)] for value in range(N)]

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
        print(result[i][j], ' ')
    print('\n')
