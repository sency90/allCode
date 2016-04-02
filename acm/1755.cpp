#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
map<int, string> itostr;
map<string, int> strtoi;
string chg(int x) {
    int a[2];
    a[0]=x/10;
    a[1]=x%10;
    string s;
    for(int i=0; i<2; i++) {
        if(i==0 && a[i]==0) continue;
        else s+=itostr[a[i]];
        if(i==0) s+='.';
    }
    return s;
}
priority_queue<string, vector<string>, greater<string> > mnh;
int main() {
    itostr[0]="zero";itostr[1]="one";itostr[2]="two";itostr[3]="three";itostr[4]="four";
    itostr[5]="five";itostr[6]="six";itostr[7]="seven";itostr[8]="eight";itostr[9]="nine";
    for(int i=0; i<10; i++) strtoi[itostr[i]]=i;
    int n, m;
    scanf("%d %d", &n, &m);
    if(n>m) swap(n,m);
    for(int i=n; i<=m; i++) {
        mnh.push(chg(i));
    }
    string s;
    int cnt=0, ans;
    while(!mnh.empty()) {
        s = mnh.top(); mnh.pop();
        int idx = s.find(".");
        if(idx==-1) {
            ans = strtoi[s];
        } else {
            ans=strtoi[s.substr(0,idx)]*10;
            ans+=strtoi[s.substr(idx+1)];
        }
        printf("%d", ans);
        if(mnh.empty()) return 0;
        if(++cnt%10==0) puts("");
        else putchar(' ');
    }
    return 0;
}
