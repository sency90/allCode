#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v,w;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,c,d,pos=0;
    cin >> n;
    bool one=false,two=false;
    for(int i=0; i<n; i++) {
        cin >> c >> d;
        if(d==2) d=-1;
        v.push_back({pos,d});
        w.push_back({c,d});
        pos+=c;
        if(d==1) one=true;
        else two=true;
    }
    if((one&&!two) || (two&&!one)) return 0&printf("Infinity");

    int lpos = pos, i=0, ans=0;
    sort(v.begin(), v.end());
    int sc=v[0].first;
    for(; i<n; i++) {
        if(v[i].second==-1) {
            if(sc<=v[i].first) {
                ans=i;
                sc=v[i].first;
            } else return 0&printf("Impossible");
        } else break;
    }
    for(; i<n; i++) {
        if(v[i].second==-1) return 0&printf("Impossible");
        else if(sc<=v[i].first) sc=v[i].first;
        else return 0&printf("Impossible");
    }

    int tmp = lpos-v[ans].first+1899;
    int tans=tmp;
    for(int i=n-1; i>=0; i--) {
        tmp-=w[i].first;
        if(tmp>=1900 && w[i].second==1) continue;
        else if(tmp<1900 && w[i].second==-1) continue;
        else return 0&printf("Impossible");
    }
    printf("%d", tans);
    return 0;
}
