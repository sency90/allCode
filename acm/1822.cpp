#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
map<int, bool> mp;
priority_queue<int> mxh;
queue<int> q;
int main() {
    int na, nb, d, cnt=0;
    scanf("%d %d", &na, &nb);
    for(int i=0; i<na; i++) {
        scanf("%d", &d);
        mp[d] = true;
        q.push(d);
    }
    for(int i=0; i<nb; i++) {
        scanf("%d", &d);
        if(mp[d]) mp[d]=false;
    }
    while(!q.empty()) {
        if(mp[q.front()]) {
            cnt++;
            mxh.push(-q.front());
        }
        q.pop();
    }
    printf("%d\n", cnt);
    while(!mxh.empty()) {
        printf("%d ", -mxh.top());
        mxh.pop();
    }
    return 0;
}
