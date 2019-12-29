#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int charDic[200];
char charIdxDic[200];
int lastPos[200];
int main() {
    int n; string s;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;

    memset(lastPos, -1, sizeof(lastPos));
    memset(charDic, -1, sizeof(charDic));

    int idx=0;
    for(int i=0; i<s.size(); i++) {
        if(charDic[s[i]]<0) {
            charDic[s[i]]=idx;
            charIdxDic[idx++]=s[i];
        }
    }

    int ans=0x3f3f3f3f;
    for(int i=0; i<s.size(); i++) {
        lastPos[charDic[s[i]]]=i;

        bool good = true;
        int mn=0x3f3f3f3f, mx=-1;
        for(int j=0; j<idx; j++) {
            if(lastPos[j]<0) good = false;
            else {
                mn = min(mn, lastPos[j]);
                mx = max(mx, lastPos[j]);
            }
        }
        if(good) {
            ans = min(ans, mx-mn+1);
        }
    }

    printf("%d", ans);
    return 0;
}
