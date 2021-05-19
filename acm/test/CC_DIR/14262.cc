#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
char s[110][110], ori[110][110];
ull cnt[4];
inline int chg(char c) {
    if(c=='R') return 0;
    else if(c=='G') return 1;
    else if(c=='B') return 2;
    else return 3;
}
void paste(int n, int m, int t) {
    for(int k=0; k<t; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!s[k+i][k+j]) s[k+i][k+j]='.';
                if(ori[i][j]=='.') continue;
                s[k+i][k+j]=ori[i][j];
            }
        }
    }
}
void count(int n, int m, int t) {
    for(int i=0; i<n+t-1; i++) {
        for(int j=0; j<m+t-1; j++) {
            cnt[chg(s[i][j])]++;
        }
    }
}
inline void print() {
    for(int i=0; i<3; i++) {
        printf("%llu\n", cnt[i]);
    }
}
int main() {
    int n,m,t;
    scanf("%d%d%d", &n,&m,&t);
    for(int i=0; i<n; i++) {
        scanf("%s", ori[i]);
    }

    if(t<=51) {
        paste(n,m,t);
        count(n,m,t);
        print();
    } else {
        paste(n,m,50);
        count(n,m,50);
        ull tmp[4], d[4];
        memcpy(tmp, cnt, sizeof(cnt));
        memset(s, 0, sizeof(s));
        memset(cnt, 0, sizeof(cnt));
        paste(n,m,51);
        count(n,m,51);
        for(int i=0; i<3; i++) {
            d[i]=cnt[i]-tmp[i];
        }
        for(int i=0; i<3; i++) {
            cnt[i]=tmp[i]+d[i]*(t-50);
        }
        print();
    }
    return 0;
}
