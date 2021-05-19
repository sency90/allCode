#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int mod = 5;
set<int> chk;
inline int chg(char x) {
    if(x=='A') return 1;
    else if(x=='C') return 2;
    else if(x=='G') return 3;
    else return 4;
}
inline char rchg(int x) {
    if(x==1) return 'A';
    else if(x==2) return 'C';
    else if(x==3) return 'G';
    else return 'T';
}
int five[11];
int spow(int x, int r) {
    if(r==0) return five[r]=1;
    else if(five[r]) return five[r];

    int ret = spow(x,r>>1);
    if(r&1) return five[r]=ret*ret*x;
    else return five[r]=ret*ret;
}
string decode(int x) {
    if(x<=0) return "";
    string s="";
    while(x!=0) {
        s=s+rchg(x%5);
        x/=5;
    }
    return s;
}
string hashcert(const string &s, const int k) {
    int val=0, n=s.size();
    for(int i=0; i<k; i++) {
        val+=chg(s[i])*five[i];
    }
    chk.erase(val);
    for(int i=k; i<n; i++) {
        val/=mod;
        val+=chg(s[i])*five[k-1];
        chk.erase(val);
    }
    auto it = chk.begin();
    string ret = decode(*it);
    if(ret.size()!=k) return "";
    else return ret;
}
void f(int x, int num) {
    if(x==0) {
        chk.insert(num);
        return;
    }
    f(x-1,num*5+1);
    f(x-1,num*5+2);
    f(x-1,num*5+3);
    f(x-1,num*5+4);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i=10; i>=0; i--) spow(5,i);
    string s; cin >> s;
    int n = s.size();
    for(int i=1; i<=6; i++) f(i,0);
    for(int k=1; k<=7; k++) {
        string ret = hashcert(s,k);
        if(ret!="") return 0&printf("%s\n", ret.c_str());
    }
    return 0;
}
