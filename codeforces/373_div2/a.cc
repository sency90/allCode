#include <cstdio>
using namespace std;
int d[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int v[100];
int main() {
    int n;
    scanf("%d", &n);
    bool inc=false, dec=false;
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        if(i>0) {
            if(v[i-1]-v[i]==1) {
                dec=true;
                if(inc) {
                    inc=false;
                    if(v[i]!=14) {
                        puts("-1");
                        return 0;
                    }
                }
            } else if(v[i-1]-v[i]==-1) {
                inc=true;
                if(dec) {
                    dec=false;
                    if(v[i]!=1) {
                        puts("-1");
                        return 0;
                    }
                }
            } else {
                puts("-1");
                return 0;
            }
        }
    }
    if(n==1) {
        if(v[0]==15) puts("DOWN");
        else if(v[0]==0) puts("UP");
        else puts("-1");
    } else {
        if(inc) {
            if(v[n-1]==15) puts("DOWN");
            else puts("UP");
        } else if(dec) {
            if(v[n-1]==0) puts("UP");
            else puts("DOWN");
        } else {
            puts("-1");
        }
    }
    return 0;
}
