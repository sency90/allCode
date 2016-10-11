#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
int a[4], b[4];
bool chk(const int *b) {
    int dif=(b[3]-b[0])*4;

    int mid=(b[1]+b[2])*2;
    if(mid!=dif) return false;

    int mean=0;
    for(int i=0; i<4; i++) mean+=b[i];
    if(mean!=dif) return false;

    return true;
}
bool verdict(int x, int y, int z, int r, int cc) {
    b[x]=a[0]; b[y]=a[1]; b[z]=a[2];
    int tmp,lim,lim2,s,e;
    if(cc==2) {
        if(y<z) {
            s=b[y];
            e=2000;
            lim=z;
            lim2=2000;
        } else if(x<z&&z<y&&y<r) {
            s=b[x];
            e=b[y];
            lim=y;
            lim2=2000;
        } else if(x<z&&r<y) {
            s=b[x];
            e=b[y];
            lim=z;
            lim2=y;
        } else if(z<x&&x<r&&r<y) {
            s=1;
            e=b[x];
            lim=x;
            lim2=y;
        } else {
            s=1;
            e=b[r];
            lim=z;
            lim2=x;
        }
        for(b[z]=s; b[z]<=e; b[z]++) {
            tmp = (b[y]+b[z])*2;
            b[r]=tmp-(b[x]+b[y]+b[z]);
            if(lim2==2000){
                if(b[r]>=b[lim]) {
                    if(chk(b)) return true;
                }
            } else {
                if(b[r]>=b[lim]&&b[r]<=b[lim2]) {
                    if(chk(b)) return true;
                }
            }
        }
    } else {
        //x,y,z,r
        if(z<r) {
            s=b[z];
            e=2000;
            lim=z;
            lim2=2000;
        } else if(y<r&&r<z) {
            s=b[y];
            e=b[z];
            lim=y;
            lim2=z;
        } else if(x<r&&r<y) {
            s=b[x];
            e=b[y];
            lim=x;
            lim2=y;
        } else {
            s=1;
            e=b[x];
            lim=1;
            lim=x;
        }
        for(int i=s; i<=e; i++) {
            b[r]=i;
            if(lim==1) {
                if(b[r]<=b[lim2]) {
                    if(chk(b)) return true;
                }
            } else if(lim2==2000) {
                if(b[lim]<=b[r]) {
                    if(chk(b)) return true;
                }
            } else {
                if(b[lim]<=b[r]&&b[r]<=b[lim2]) {
                    if(chk(b)) return true;
                }
            }
        }
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    bool hasAns=true;
    if(n==0) {
        puts("YES");
        printf("1\n1\n3\n3\n");
        return 0;
    } else if(n==1) {
        hasAns=true;
        if(a[0]&1) {
            b[1]=a[0];
            b[2]=a[0]+2;
            b[3]=b[2]+((a[0]-1)/2);
            b[0]=b[1]-((a[0]-1)/2);
        } else {
            b[1]=b[2]=a[0];
            b[3]=b[2]+a[0]/2;
            b[0]=b[2]-a[0]/2;
        }
    } else if(n==2) {
        sort(a, a+n);
        if(verdict(0,1,2,3,2));
        else if(verdict(0,2,1,3,2));
        else if(verdict(0,3,1,2,2));
        else if(verdict(1,2,0,3,2));
        else if(verdict(1,3,0,2,2));
        else if(verdict(2,3,0,1,2));
        else hasAns=false;
    } else if(n==3) {
        sort(a, a+n);
        if(verdict(0,1,2,3,3));
        else if(verdict(0,1,3,2,3));
        else if(verdict(0,2,3,1,3));
        else if(verdict(1,2,3,0,3));
        else hasAns=false;
    } else if(n==4) {
        sort(a, a+n);
        hasAns=chk(a);
        memcpy(b,a,sizeof(b));
    }
    if(hasAns) {
        puts("YES");
        map<int, int> ans;
        for(int i=0; i<4; i++) ans[b[i]]++;
        for(int i=0; i<n; i++) ans[a[i]]--;
        for(auto &p : ans) {
            if(p.second>0) {
                for(int i=0; i<p.second; i++) {
                    printf("%d\n", p.first);
                }
            }
        }
    }else puts("NO");
    return 0;
}
