#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int> > mnh;
int main()  {
    int n, m, x, y, tmp, cnt[32001];
    memset(cnt, 0, sizeof(cnt));
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        cnt[y]++;
    }
    for(int i=1; i<=n; i++) {
        if(cnt[i]==0) {
            v[0].push_back(i);
            cnt[i]++;
        }
    }
    mnh.push(0);
    while(!mnh.empty()) {
        tmp = mnh.top(); mnh.pop();
        if(tmp!=0) printf("%d ", tmp);
        for(int i=0; i<v[tmp].size(); i++) {
            cnt[v[tmp][i]]--;
            if(cnt[v[tmp][i]]==0) mnh.push(v[tmp][i]);
        }
    }
}

