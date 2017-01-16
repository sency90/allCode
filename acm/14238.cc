#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
char d[51][51][51][3][3];
string s="";
char f(int a, int b, int c, int pv, int ppv) {
    if(a<0||b<0||c<0) return 0;
    char &ret = d[a][b][c][pv][ppv];
    if(ret>=0) return ret;
    else ret=0;
    if(a==0&&b==0&&c==0) return ret=1;
    if(f(a-1,b,c,0,pv)) ret='A';
    else if(ppv==2) {
        if(pv!=1 && f(a,b-1,c,1,pv)) ret='B';
    } else if(pv==2) {
        if(f(a,b-1,c,1,pv)) ret='B';
    } else if(pv==1) {
        if(f(a,b,c-1,2,pv)) ret='C';
    } else {
        if(f(a,b-1,c,1,pv)) ret='B';
        else if(f(a,b,c-1,2,pv)) ret='C';
    }
    if(ret) s+=ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str; cin >> str;
    int a=0,b=0,c=0;
    memset(d, -1, sizeof(d));
    for(int i=0; i<str.size(); i++) {
        if(str[i]=='C') c++;
        else if(str[i]=='B') b++;
        else a++;
    }
    if(f(a,b,c,0,0)) return 0&printf("%s", s.c_str());
    else if(f(a,b,c,1,0)) return 0&printf("%s", s.c_str());
    else if(f(a,b,c,2,0)) return 0&printf("%s", s.c_str());
    else puts("-1");
    return 0;
}
