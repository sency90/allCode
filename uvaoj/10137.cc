#include <stdio.h>
const int mask = (1<<10)-1;
int v[1001], cnt[mask+1], idx[2][mask+1];
inline int abs(int x) { return x<0?-x:x; }
int main() {
    while(true) {
        int n, sum=0; scanf("%d", &n);
        if(n==0) break;

        for(int i=0; i<n; i++) {
            int x,y; scanf("%d.%d",&x,&y);
            v[i]=x*100+y;
            sum += v[i];
        }

        //count sorting start
        for(int i=0; i<=mask; i++) cnt[i]=0;
        for(int i=0; i<n; i++) cnt[v[i]&mask]++;
        for(int i=1; i<=mask; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[0][--cnt[v[i]&mask]] = i;

        for(int i=0; i<=mask; i++) cnt[i]=0;
        for(int i=0; i<n; i++) cnt[(v[i]>>10)&mask]++;
        for(int i=1; i<=mask; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[1][--cnt[(v[idx[0][i]]>>10)&mask]] = idx[0][i];

        for(int i=0; i<=mask; i++) cnt[i]=0;
        for(int i=0; i<n; i++) cnt[v[i]>>20]++;
        for(int i=1; i<=mask; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[0][--cnt[v[idx[1][i]]>>20]] = idx[1][i];
        //count sorting end

        int q=sum/n, r=sum%n;
        int a=n-r, ans=0;

        for(int i=0; i<a; i++) {
            if(v[idx[0][i]]<q) ans+=q-v[idx[0][i]];
            else break;
        }
        for(int i=a; i<n; i++) {
            if(v[idx[0][i]]<q+1) ans+=q+1-v[idx[0][i]];
            else break;
        }
        printf("$%d.%02d\n", ans/100, ans%100);
    }
    return 0;
}
