#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
char a[30], b[30];
int chg(int x) {
    if(x>=10) return chg(x%10 + chg(x/10));
    else return x;
}
int calc(char *x) {
    int sum=0;
    for(int i=0; x[i]; i++) {
        if(isalpha(x[i])) {
            if(islower(x[i])) sum+=x[i]-'a'+1;
            else sum+=x[i]-'A'+1;
        }
    }
    return chg(sum);
}
int main() {
    while(gets(a)) {
        gets(b);
        int x=calc(a), y=calc(b);
        if(x>y) swap(x,y);
        if(x==0 && y==0) puts("0 %%");
        else printf("%.2lf %%\n", double(x)/y*100);
    }
    return 0;
}
