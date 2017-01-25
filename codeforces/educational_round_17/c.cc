#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define r2 (r<<1)
#define m2 ((s+e)>>1)
int cnt[26], cnta[26], cntb[26], tcnt[26];
bool p[26];
deque<pii> dq;
vector<int> ch;
struct Fen{
    int s,e;
    vector<int> tree;
    Fen(){}
    void init(int n) {
        s=1; e=n;
        tree.resize(n,0);
    }

    void add(int i, int by) {
        for(i++;i<=e;i+=i&-i) tree[i]+=by;
    }
    ll sum(int i) {
        ll ret=0;
        for(i++;i;i-=i&-i) ret+=tree[i];
        return ret;
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string a,b;
    cin>>a>>b;
    for(int i=0; i<a.size(); i++) cnta[a[i]-'a']++;

    Fen fen[26];
    for(int i=0; i<26; i++) fen[i].init(b.size());
    for(int i=0; i<b.size(); i++) {
        cntb[b[i]-'a']++;
        fen[b[i]-'a'].add(i,1);
    }
    int lo=0, hi=b.size()-1;
    for(int i=0; i<26; i++) {
        if(cntb[i]-cnta[i]>0) {
            cnt[i]=cntb[i]-cnta[i];
            ch.push_back(i);
            lo++;
            p[i]=true;
        }
    }
    auto chk = [&](){
        for(int i=0; i<26; i++) {
            if(cnt[i]) return false;
        }
        return true;
    };
    if(chk()) return 0&printf("%s", b.c_str());

    int mns=-1,mnlen=-1;
    auto chk2 = [&]() {
        for(int i=0; i<26; i++) {
            if(tcnt[i]) return false;
        }
        return true;
    };
    auto check = [&](int x) {
        for(int i=0; i<x; i++) {
            int idx=b[i]-'a';
            if(tcnt[idx]==0) continue;
            tcnt[idx]--;
        }
        if(chk2()) {
            mns=0;
            mnlen=x-1;
            return true;
        }
        for(int l=0,r=x; r<b.size(); l++, r++) {
            int idxl=b[l]-'a', idxr=b[r]-'a';
            if(p[idxl]) tcnt[idxl]++;
            if(p[idxr]) {
                if(tcnt[idxr]!=0) tcnt[idxr]--;
            }
            if(chk2()) {
                mns=l+1;
                mnlen=r;
                return true;
            }
        }
        return false;
    };
    while(lo<hi) {
        memcpy(tcnt, cnt, sizeof(cnt));
        int mid = (lo+hi)>>1;
        if(check(mid)) hi=mid-1;
        else lo=mid;
    }
    if(mns<0) return 0&puts("-");
    string ans = b.substr(0,mns+1)+b.substr(mnlen+1);
    printf("%s", ans.c_str());
    return 0;
}
