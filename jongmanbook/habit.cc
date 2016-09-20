#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> getsfx(const string &s) {
    const int n = s.size();
    vector<int> sfx(n), ord(n+1,0), nord(n+1), cnt(max(n+1,256)), aux(n+1);
    int p = 1;
    for(int i=0; i<n; i++){
        sfx[i] = i;
        ord[i] = s[i];
    }
    ord[n]=0;
    int pnt = 1;
    while(1){
        cnt.clear(); cnt.resize(max(n+1,256));
        for(int i=0; i<n; i++) cnt[ord[min(i+p, n)]]++;
        for(int i=1; i<=n || i<=255; i++) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--) aux[--cnt[ord[min(i+p, n)]]] = i;

        cnt.clear(); cnt.resize(max(n+1,256));
        for(int i=0; i<n; i++) cnt[ord[i]]++;
        for(int i=1; i<=n || i<=255; i++) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[ord[aux[i]]]] = aux[i];

        if(pnt == n) break;
        pnt = 1;
        nord[sfx[0]] = 1;
        for(int i=1; i<n; i++){
            if(ord[sfx[i-1]] != ord[sfx[i]] || ord[sfx[i-1] + p] != ord[sfx[i] + p]){
                pnt++;
            }
            nord[sfx[i]] = pnt;
        }
        ord = nord;
        p *= 2;
    }
    return sfx;
}

int main() {
    vector<int> sfx;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        int k, mx=0;
        cin >> k >> s;
        sfx = getsfx(s);
        int n=s.size();
        auto lcp = [&](int i, int j)->int{
            int cnt=0;
            for(; i<n&&j<n; i++,j++) {
                if(s[i]==s[j]) cnt++;
                else break;
            }
            return cnt;
        };
        for(int i=0; i+k<=n; i++) {
            mx = max(mx, lcp(sfx[i],sfx[i+k-1]));
        }
        printf("%d\n", mx);
    }
    return 0;
}
