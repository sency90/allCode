#include <stdio.h>
int v[367];
int dx[]={0,1,-2,1,0,1,0,1,1,0,1,0,1};
inline void init() {
    for(int i=1; i<=12; i++) dx[i]+=dx[i-1];
}
inline int chg(int month,int day) {
    return dx[month-1]+(month-1)*30+day;
}
inline int max(int x,int y) { return x>y?x:y; }
int main() {
    init();
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int sx,sy,ex,ey;
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        int x=chg(sx,sy),y=chg(ex,ey);
        v[x] = max(v[x],y);
    }
    int sdate=chg(3,1),edate=chg(12,1),cnt=0;
    for(int i=sdate;i<edate;) {
        int ori = i;
        for(int j=i; j>=1; j--) i = max(i,v[j]);
        if(i<=ori) return 0&puts("0");
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
