#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void fan(char s[]) {
    for(int i=0, j=strlen(s)-1; i<=j; i++, j--) {
        swap(s[i],s[j]);
    }
}
char ans[10001][4000];
char x[4000],y[4000],z[4000];
int main() {
    int i,n,p=0,k,l;
    strcpy(ans[1],"1");
    strcpy(ans[2],"3");
    strcpy(ans[3],"4");
    for(int mm=4; mm<=10000; mm++) {
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        p=0;
        strcpy(x,ans[mm-1]);
        strcpy(y,ans[mm-2]);
        fan(x);fan(y);
        k=strlen(x);
        l=strlen(y);
        for(i=0; i<k || i<l; i++) {
            if(i<k && i<l) z[i] = x[i]+y[i] + p-'0';
            else if(i<k && i>=l) z[i]=x[i]+p;
            else if(i>=k && i<l) z[i]=y[i]+p;
            if(z[i]>'9') {
                z[i]-=10;
                p=1;
            }
            else p=0;
        }
        if(p) z[i++]='1';
        z[i]='\0';
        fan(x);fan(y);fan(z);
        strcpy(ans[mm],z);
    }
    while(~scanf("%d",&n)) printf("%s\n",ans[n]);
    return 0;
}
