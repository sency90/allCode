#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
typedef pair<int,double> pid;
char s[101];
set<string> dict;
vector<string> v;
vector<pair<pid,int> > g;
bool cmp(const pair<pid,int> &l, const pair<pid,int> &r) {
    if(l.first.first == r.first.first) {
        if(l.first.second==r.first.second) return l.second<r.second;
        else return l.first.second < r.first.second;
    } else return l.first.first > r.first.first;
}
int main() {
    for(int z=1;;z++) {
        int n,p; scanf("%d %d", &n,&p); getchar();
        if(n==0 && p==0) return 0;
        else {dict.clear(); v.clear(); g.clear(); if(z!=1) puts(""); }
        char c;
        for(int i=0; i<n; i++) {
            gets(s);
            int len = strlen(s);
            dict.insert(string(s).substr(0,len));
        }
        for(int i=0; i<p; i++) {
            gets(s);
            int len = strlen(s);
            v.push_back(string(s).substr(0,len));
            double d; int r, cnt=0;
            scanf("%lf %d",&d,&r); getchar();
            for(int j=0; j<r; j++) {
                gets(s);
                int len = strlen(s);
                if(dict.count(string(s).substr(0,len))) cnt++;
            }
            g.push_back(pair<pid,int>(pid(cnt,d),i));
        }
        printf("RFP #%d\n", z);
        if(g.empty()) { puts(""); continue; }
        sort(g.begin(), g.end(), cmp);
        printf("%s\n", v[g[0].second].c_str());
    }
    return 0;
}
