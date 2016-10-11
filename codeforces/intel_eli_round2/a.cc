#include <string>
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> day;
void init() {
    day["sunday"]=0;
    day["monday"]=1;
    day["tuesday"]=2;
    day["wednesday"]=3;
    day["thursday"]=4;
    day["friday"]=5;
    day["saturday"]=6;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,e;
    cin>>s>>e;
    init();
    if(s==e) puts("YES");
    else {
        int ss=day[s], ee=day[e];
        if(ee>ss) {
            if(ee-ss==2||ee-ss==3) puts("YES");
            else puts("NO");
        } else {
            if((ss+2)%7==ee||(ss+3)%7==ee) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
