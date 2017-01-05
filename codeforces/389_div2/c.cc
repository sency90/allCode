#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<char,int> mp;
bool chk[5];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    int n; cin>>n;
    cin >> s;
    mp['L']=0;
    mp['R']=1;
    mp['D']=2;
    mp['U']=3;
    int cnt=1;
    for(int i=0; i<s.size(); i++) {
        chk[mp[s[i]]]=true;
        if(chk[mp[s[i]]^1]) {
            cnt++;
            int x = mp[s[i]];
            if(x==0) chk[1]=chk[2]=chk[3]=false;
            else if(x==1) chk[0]=chk[2]=chk[3]=false;
            else if(x==2) chk[0]=chk[1]=chk[3]=false;
            else if(x==3) chk[0]=chk[1]=chk[2]=false;
        }
    }
    printf("%d", cnt);
    return 0;
}
