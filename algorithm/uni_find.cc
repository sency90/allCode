#include <cstdio>
using namespace std;
int p[100001];
void init(int n) {
    for(int i=0; i<=n; i++) p[i]=i;
}
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
int uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    p[y]=x;
    return true;
}
int main() {
    int n=6; init(n);
    uni(2,3); uni(4,5); uni(3,1);
    printf("%d %d %d\n",find(1), find(5), find(6));
    return 0;
}
