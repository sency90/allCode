#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <queue>
using namespace std;
map<int, string> itostr;
map<string, int> strtoi;
string chg(int x) {
    int a[2];
    a[0]=x/10;
    a[1]=x%10;
    string s;
    for(int i=0; i<2; i++) {
        if(i==0 && a[i]==0) s+='a';
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
    for(int i=n; i<=m; i++) {
        mnh.push(chg(i));
    }
    string s;
    int cnt=0, ans;
    while(!mnh.empty()) {
        s = mnh.top(); mnh.pop();
        if(s[0]=='a') {
            ans = strtoi[s.substr(2)];
        } else {
            int idx = s.find(".");
            ans=strtoi[s.substr(0,idx)]*10;
            ans+=strtoi[s.substr(idx+1)];
        }
        printf("%d ", ans);
        if(++cnt%10==0) puts("");
    }
    return 0;
}
