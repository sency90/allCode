#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cstring>
using namespace std;
char v[11], rv[11];
char op[11], mn[11], mx[11];
int n;
bool chk(char& o, char& x, char& y) {
    if(o=='<') return x<y;
    else return x>y;
}
bool isFirst = true;
void memorize(char *x) {
    char res[11];
    sprintf(res, "%s", x);
    if(isFirst) {
        strcpy(mn, res);
        isFirst = false;
    } else strcpy(mx, res);
}
int main() {
    int i=0;
    char c;
    strcpy(v, "0123456789");
    strcpy(rv, "9876543210");
    scanf("%d ", &n);
    while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
        if(c==' ') continue;
        op[i++]=c;
    }
    do{ for(i=0; i<n; i++) {
            if(!chk(op[i], v[i], v[i+1])) break;
        }
        if(i==n) {
            memorize(v);
            break;
        }
    }while(next_permutation(v, v+10));

    do{ for(i=0; i<n; i++) {
            if(!chk(op[i], rv[i], rv[i+1])) break;
        }
        if(i==n) {
            memorize(rv);
            break;
        }
    }while(prev_permutation(rv, rv+10));

    for(int i=0; i<=n; i++) putchar(mx[i]);
    puts("");
    for(int i=0; i<=n; i++) putchar(mn[i]);
}
