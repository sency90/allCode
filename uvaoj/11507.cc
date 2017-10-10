#include <iostream>
using namespace std;
#define X 1
#define Y 2
#define Z 3
#define MX 4
#define MY 5
#define MZ 6
int chg(char *x) {
    if(x[1]=='o') return 0;
    else if(x[1]=='x') return ((x[0]=='-')?3:0)+1;
    else if(x[1]=='y') return ((x[0]=='-')?3:0)+2;
    else return ((x[0]=='-')?3:0)+3;
}

int calc(int cur, int dir) {
    if(dir==0) return cur;
    else if(cur==X) return dir;
    else if(cur==MX) {
        if(dir+3>6) return dir-3;
        else return dir+3;
    } else if(cur==Y) {
        if(dir==Z||dir==MZ) return cur;
        else if(dir==Y) return MX;
        else return X;
    } else if(cur==Z) {
        if(dir==Y||dir==MY) return cur;
        else if(dir==Z) return MX;
        else return X;
    } else if(cur==MY) {
        if(dir==Z||dir==MZ) return cur;
        else if(dir==Y) return X;
        else return MX;
    } else {
        if(dir==Y||dir==MY) return cur;
        else if(dir==Z) return X;
        else return MX;
    }
}
char s[3];
int main() {
    while(true) {
        int n; scanf("%d",&n);
        if(n==0) return 0;
        int cur=X;
        for(int i=0; i<n-1; i++) {
            scanf("%s", s);
            cur = calc(cur,chg(s));
        }
        if(cur==X) puts("+x");
        else if(cur==Y) puts("+y");
        else if(cur==Z) puts("+z");
        else if(cur==MX) puts("-x");
        else if(cur==MY) puts("-y");
        else if(cur==MZ) puts("-z");
    }
    return 0;
}
