#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 21;

int n, m;
bool uzeo[MAXN];
vector <int> E[MAXN];

int calc (int x) {
  if (x == n) return 1;
  int ret = calc(x+1); //이게 x를 안고르는 경우

  bool ok = 1;
  for (auto v: E[x])
    if (uzeo[v]) ok = 0; //x-v끼리 연결되어 있는데 v를 고른 경우에는 x를 고를 수 없다. 왜냐하면 x,v가 둘이 공존해서는 안된다는게 문제니까.

    //x를 고를거야
  if (ok){
    uzeo[x] = 1;
    ret += calc(x+1);
    uzeo[x] = 0;
  }

  return ret;
}

int main (void){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    --x; --y; 
    E[x].push_back(y);
    E[y].push_back(x);
  }

  printf("%d\n", calc(0));
  return 0;
}
