#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s;
int d[41];
bool chk[41];
int chg(char x,char y) {
    return (x-'0')*10 + (y-'0');
}
int f(int x) {
    if(x==1 && s[x]!='0') return 1;
    else if(x==0) return 1;
    //else if(x<0) return 0;
    if(chk[x]) return d[x];
    chk[x]=true;

    int digit = chg('0',s[x]);
    if(digit!=0) d[x]+=f(x-1);
    if(x-1>0) {
        if(s[x-1]!='0') {
            digit = chg(s[x-1],s[x]);
            if(digit>=1 && digit<=34) d[x]+=f(x-2);
        }
    }
    return d[x];
}
int main() {
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    s="0"+s;
    printf("%d",f(s.size()-1));
    return 0;
}
