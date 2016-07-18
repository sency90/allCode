#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
bool f(string &a) {
    int cntw,cnt;;
    int i,j,k,l,m;
    cntw=cnt=0;
    i=0; j=k=l=m=a.size();
    for(;i<a.size(); i++) {
        if(a[i]=='w') cntw++;
        else {
            j=i;
            break;
        }
    }

    for(;j<a.size(); j++) {
        if(a[j]=='o') cnt++;
        else {
            k=j;
            break;
        }
    }
    if(cntw != cnt) return false;
    else cnt=0;

    for(;k<a.size(); k++) {
        if(a[k]=='l') cnt++;
        else {
            l=k;
            break;
        }
    }
    if(cntw != cnt) return false;
    else cnt=0;

    for(;l<a.size(); l++) {
        if(a[l]=='f') cnt++;
        else break;
    }
    if(cntw != cnt) return false;
    else cnt=0;

    if(l==a.size()) return true;
    string s=a.substr(l);
    return f(s);
}
int main() {
    string s;
    cin >> s;
    if(f(s)) puts("1");
    else puts("0");
    return 0;
}
