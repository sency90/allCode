//354 Div2. C. Vasya and String
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//int sumA[100002], sumB[100002];
vector<int> sumA, sumB;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s='a'+s;

    sumA.clear(); sumA.resize(n+1, 0);
    sumB.clear(); sumB.resize(n+1, 0);
    for(int i=1; i<=n; i++) {
        if(s[i]=='a') {
            sumA[i]=sumA[i-1]+1;
            sumB[i]=sumB[i-1];
        }
        else {
            sumA[i]=sumA[i-1];
            sumB[i]=sumB[i-1]+1;
        }
    }

    int ans=-1;
    if(sumA[n]<=sumB[n]) {
        for(int i=0; i<sumA.size(); i++) {
            if(s[i]=='a') {
                auto jt = lower_bound(sumA.begin()+i+1, sumA.end(), sumA[i]+k+1);
                ans = max(ans, (int)(jt-(sumA.begin()+i+1)));
            }
        }
    }
    s[0]='b';
    if(sumA[n]>=sumB[n]) {
        for(int i=0; i<sumB.size(); i++) {
            if(s[i]=='b') {
                auto jt = lower_bound(sumB.begin()+i+1, sumB.end(), sumB[i]+k+1);
                ans = max(ans, (int)(jt-(sumB.begin()+i+1)));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
