#include <cstdio>
#include <algorithm>
using namespace std;
int p[50004];
void init(int x) {
    for(int i=0; i<=50003; i++) p[i]=i;
}
int find(int x) {
    if(x==p[x]) return x;
    else return p[x]=find(p[x]);
}
bool uni(int x, int y) {
    int x=find(x), y=find(y);
    if(x==y) return false;
    else {
        if(x<y) swap(x,y);
        p[y]=x;
        return true;
    }
}
int main() {
    int n, k, cnt=0;
    scanf("%d%d", &n,&k);
    for(int i=0; i<k; i++) {
        int t,a,b;
        scanf("%d%d%d", &t,&a,&b);

        if(a>n || b>n) cnt++;
        else {
            int x=find(a), y=find(b);
            if(t==1) {
                if(x==y) continue

            } else {
                if(x==y) cnt++;
                else {
                    
                }
            }
        }
    }
    return 0;
}
