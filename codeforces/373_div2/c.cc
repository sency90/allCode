#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char a[200001], b[200001], c;
int chg(char x) { return x-'0'; }
int main() {
    int n, t, idx=0;
    scanf("%d%d ",&n,&t);
    bool turn = false;
    for(int i=0; i<n; i++) {
        scanf("%c",&c);
        if(c=='.') {
            a[idx]=0;
            idx=0;
            turn = true;
        } else {
            if(!turn) a[idx++]=c;
            else b[idx++]=c;
        }
    }
    b[idx]=0;
    int sz=strlen(b),start=-1, end=-1;
    for(int i=0; i<sz; i++) {
        if(b[i]>='5') {
            b[i+1]=0;
            end=i;
            break;
        } else if(b[i]=='4'){
            if(start==-1) start=i;
        } else {
            if(start!=-1) start=-1;
        }
    }
    if(end==-1) {
        printf("%s.%s",a,b);
        return 0;
    }
    int carry=0;
    if(start!=-1) {
        int y=max(end-t,start);
        if(end-t+1<=start) {
            b[y]=0;
            if(y==0) carry=1;
            else b[y-1]=b[y-1]+1;
        } else {
            b[y]='5';
            b[y+1]=0;
        }
    } else {
        b[end]=0;
        if(end==0) carry=1;
        else b[end-1]=b[end-1]+1;
    }
    int cntz=0, alen=strlen(a);
    if(carry) {
        for(int i=alen-1; alen>=0; i--) {
            if(a[i]=='9'&&carry) {
                cntz++;
                a[i]='0';
            } else {
                if(carry) a[i]=a[i]+1;
                carry=0;
                break;
            }
        }
    }
    if(b[0]==0) {
        if(cntz==alen) putchar('1');
        printf("%s", a);
    } else {
        if(cntz==alen) putchar('1');
        printf("%s.%s",a,b);
    }
    return 0;
}
