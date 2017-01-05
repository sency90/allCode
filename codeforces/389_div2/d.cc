#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
int cnt=1;
const int mask=0x10000000;
struct TrieNode{
    TrieNode *room[26];
    int tno;
    //bool isTerminal;
    TrieNode():tno(0){ memset(room, 0, sizeof(room)); }
    ~TrieNode() {
        for(int i=0; i<26; i++) {
            if(room[i]) delete room[i];
        }
    }
    int& insert(const char *s, int t, bool flag) {
        if(*s==0) {
            //if(flag) tno|=flag;
            if(tno) return tno;
            else {
                if(t) tno=t;
                else tno=cnt++;
                if(flag) tno|=mask;
                return tno;
            }
        }
        int x = *s-'a';
        if(!room[x]) room[x]=new TrieNode();
        return room[x]->insert(s+1,t,flag);
    }
    int find(const char *s) {
        if(*s==0) return tno;
        int x=s[0]-'a';
        if(room[x]) return room[x]->find(s+1);
        else return 0;
    }
};
vector<int> v[100001];
map<int,int> mp;
set<int> st,hubo;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    TrieNode tn;
    int k,n; cin>>k>>n;
    string s,r; int b;
    vector<int> tno,tno2;
    for(int i=0; i<k; i++) {
        cin>>s>>b;
        r=s;
        reverse(r.begin(),r.end());
        int tno = tn.find(r.c_str());
        if(tno>=mask) {
            tno-=mask;
            st.insert(tno);
        }
        if(tno) v[tno].push_back(b);
        else v[cnt].push_back(b);
        mp[b]++;
        tn.insert(s.c_str(),tno,(r==s));
    }
    auto cmp = [&](int i, int j)->bool{
        return i>j;
    };
    ll ans=0LL;
    for(int i=1; i<cnt; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
        for(int j=0; j+1<v[i].size(); j+=2) {
            if(v[i][j]+v[i][j+1]>0) {
                printf("%d, %d\n", v[i][j], v[i][j+1]);
                ans+=v[i][j]+v[i][j+1];
            }
            else if(v[i][j]>0&&st.count(i)) {
                hubo.insert(v[i][j]);
                break;
            } else break;
        }
    }
    if(hubo.size()>0){
        auto it = hubo.end();
        it--;
        if(*it>0) ans+=(*it);
    }
    printf("%lld", ans);
    return 0;
}

