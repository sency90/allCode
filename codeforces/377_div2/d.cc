#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <ciso646>
using namespace std;
#define foi(i,a,n) for(int i=a;i<n;i++)
#define Foi(i,a,n,x) for(int i=a;i<n;i+=x)
#define fod(i,a,n) for(int i=a;i>n;i--)
#define Fod(i,a,n,x) for(int i=a;i>n;i-=x)
#define iosinit(x) ios::sync_with_stdio(x); cin.tie(x)
int d[100001],a[100001];
bool chk[100001];
int cnt[100001];
int n,m;
bool check(int x) {
    queue<int> q;
    memset(chk,false,sizeof(chk));
    memset(cnt,0,sizeof(cnt));
    int sz=0,t=0; chk[0]=true;
    fod(i,x,0) {
        if(!chk[d[i]]) {
            chk[d[i]]=true;
            cnt[d[i]]+=a[d[i]];
            q.push(d[i]);
        } else {
            if(!q.empty()) {
                t = q.front();
                if(--cnt[t]==0) {
                    sz++;
                    q.pop();
                }
            }
        }
    }
    foi(i,1,m) if(!chk[i]) return false;
    return (sz==m);
}
int main() {
    iosinit(0);
    cin >> n >> m;
    foi(i,1,n+1) cin>>d[i];
    foi(i,1,m+1) cin>>a[i];
    int l=0,r=n+1;
    while(l+1<r) {
        int mid = (l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r==n+1?-1:r);
    return 0;
}
