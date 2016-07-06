#include <stdio.h>
int p[150000];
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void uni(int x, int y) {
    x=find(x); y=find(y);
    if(x!=y) p[y]=x;
}
int main() {
    int n,k,cnt=0,t,x,y;
    scanf("%d%d",&n,&k);
    int tmp = n*3;
    for(int i=0; i<tmp; i++) p[i]=i;
    for(int i=0; i<k; i++) {
        scanf("%d%d%d",&t,&x,&y);
        x--; y--;
        if(x<0||x>=n||y<0||y>=n) cnt++;
        else if(t==1) {
            if(find(x)==find(y+n)||find(x)==find(y+2*n)) cnt++;
            else {
                uni(x,y);
                uni(x+n,y+n);
                uni(x+2*n,y+2*n);
            }
        } else {
            if(find(x)==find(y)||find(x)==find(y+2*n)) cnt++;
            else {
                uni(x,y+n);
                uni(x+n,y+2*n);
                uni(x+2*n,y);
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
