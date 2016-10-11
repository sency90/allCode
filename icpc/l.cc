#include <cstdio>
#include <queue>
using namespace std;
queue<int> q1, q2;
int v[1001],t[1001];
int main() {
    int n,w,l,d;
    scanf("%d%d%d",&n,&w,&l);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        q1.push(d);
    }
    int sum=0, sidx=0, eidx=0, ansTime=0, cnt=0;
    while(!q1.empty()) {
        int x = q1.front();
        if(x+sum<=l && cnt+1<=w) {
            cnt++;
            q2.push(x);
            q1.pop();
            sum+=x;
            for(int i=sidx; i<=eidx; i++) {
                t[i]++;
            }
            eidx++;
            ansTime++;
        } else {
            int addtime=(w-t[sidx]);
            if(addtime) {
                for(int i=sidx; i<eidx; i++) {
                    t[i]+=addtime;
                }
                ansTime+=addtime;
            }
            sidx++;
            x=q2.front(); q2.pop();
            sum-=x;
            cnt--;

            x=q1.front();
            if(x+sum<=l && cnt+1<=w) {
                cnt++;
                q2.push(x);
                q1.pop();
                sum+=x;
                for(int i=sidx; i<=eidx; i++) {
                    t[i]++;
                }
                eidx++;
                ansTime++;
            }
        }
    }
    ansTime+=(w-t[eidx-1])+1;
    printf("%d\n", ansTime);
    return 0;
}
