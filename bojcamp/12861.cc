#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int T, n, p, q, A[110], dp[110][110];

int getCost(int x, int y) {
  int lo = A[x], hi = A[y];
  int ret = hi - lo + 1;
  if (x == 0) {
    ret += lo - 1;
  } else {
    ret += lo - A[x - 1] - 1;
  }
  if (y == q - 1) {
    ret += p - (hi + 1) + 1;
  } else {
    ret += A[y + 1] - hi - 1;
  }
  return ret;
}

int func(int x, int y) {
  if (x > y) {
    return 0;
  }
  
  int& ret = dp[x][y];
  if (ret != INF) {
    return ret;
  }
  
  for (int i = x ; i <= y ; ++i) {
    int cost = getCost(x, y) - 1;
    ret = min(ret, func(x, i - 1) + func(i + 1, y) + cost);
  }
  return ret;
}

int main() {
  scanf("%d%d", &p, &q);
  for (int i = 0 ; i < q ; ++i) {
    scanf("%d", &A[i]);
  }
  sort(A, A + q);
  
  for (int i = 0 ; i < q ; ++i) {
    for (int j = 0 ; j < q ; ++j) {
      dp[i][j] = INF;
    }
  }
  int sol = func(0, q - 1);
  printf("%d\n", sol);
}