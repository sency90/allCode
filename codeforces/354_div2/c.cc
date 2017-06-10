#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int d[100001],n,k;
bool judge(int x) {
    for(int i=x; i<=n; i++) {
        if(min(d[i]-d[i-x], x-(d[i]-d[i-x]))<=k) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >>n>>k>>s;
    for(int i=0; i<n; i++) {
        d[i+1]=d[i]+(s[i]=='a');
    }
    int lo=1, hi=s.size();
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if(judge(mid)) lo=mid+1;
        else hi=mid-1;
    }
    printf("%d\n",lo-1);
    return 0;
}
