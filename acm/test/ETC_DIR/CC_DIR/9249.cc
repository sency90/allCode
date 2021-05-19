#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int sz=0;
bool isDiffSide(int x, int y) {
    if((x<sz&&sz<y)||(y<sz&&sz<x)) return true;
    else return false;
}
pair<int,int> getlcp(const string& s) {
    int n=s.size();
    int lim = max(n+1,256);
    vector<int> sfx(n), idx(n+1), g(n+1), ng(n+1), cnt;
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=s[i];
    }
    g[n]=0;
    for(int t=1; t<n; t<<=1) {
        cnt.clear(); cnt.resize(lim);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[--cnt[g[min(i+t,n)]]]=i;

        cnt.clear(); cnt.resize(lim);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[idx[i]]]]=idx[i];

        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        ng[sfx[0]]=1; ng[n]=0;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1], sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g=ng;
    }
    vector<int> prevsfx(n);
    int mx=0, mxi=0;
    prevsfx[sfx[0]]=-1;
    for(int i=1; i<n; i++) prevsfx[sfx[i]] = sfx[i-1];
    for(int i=0, c=0; i<n; i++) {
        if(prevsfx[i]==-1) continue;
        else {
            if(!isDiffSide(i+c, prevsfx[i]+c)) {
                c=0; continue;
            }
            while(s[i+c]==s[prevsfx[i]+c]) c++;
            if(mx<c) {
                mx=c;
                mxi=i;
            }
            c = max(c-1,0);
        }
    }
    return make_pair(mxi,mx);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s2,s1;
    cin >> s1 >> s2;
    sz=s1.size();
    s1+='.'+s2;
    pair<int,int> ans = getlcp(s1);
    cout << ans.second << "\n";
    cout << s1.substr(ans.first, ans.second);
    return 0;
}
