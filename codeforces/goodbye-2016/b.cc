#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,t,d=0;
    string dir;
    cin >> n;
    bool ans=true;
    for(int i=0; i<n; i++) {
        cin >> t >> dir;
        if(dir[0]=='S') {
            if(d<20000) d+=t;
            else ans=false;
            if(d>20000) ans=false;
        } else if(dir[0]=='N') {
            if(d==0) ans=false;
            else if(d<=20000) d-=t;
            if(d<0) ans=false;
        } else {
            if(d>=20000||d<=0) ans=false;
        }
    }
    if(!ans) return 0&printf("NO");
    else {
        if(d==0) printf("YES");
        else printf("NO");
    }
    return 0;
}
