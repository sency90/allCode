#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
map<string, vector<int>> ss;
map<ll, vector<pii>> h;
vector<ll> dp;
vector<string> str;

class Fenwick{
public:
    int s,e;
    vector<ll> tree;
    Fenwick(){} Fenwick(int n):s(1),e(n),tree(n+2,0LL) {}
    void range_update(int l, int r, ll by) {
        internal_update(l,by);
        internal_update(r+1,-by);
    }
    ll query(int at) {
        ll ret=0LL;
        for(int i=at; i>=1; i-=i&-i) ret+=tree[i];
        return ret;
    }

private:
    void internal_update(int at, ll by) {
        for(int i=at; i<=e && i; i+=i&-i) tree[i]+=by;
    }
};
vector<Fenwick> fen;

const ll M = 2147483629LL;
ll mod(ll x) { return (x>=M)?x%M:x; }
ll pow(ll x, int a) {
    ll &ret = dp[a];
    if(ret) return ret;
    if(a==0) return ret=1LL;

    ret = mod(pow(x,a>>1)*pow(x,a>>1));
    if(a&1) return ret=mod(ret*x);
    else return ret;
}

void hashing(string &line, int l, int k, ll x, int idx) {
    ll init=M;
    for(int i=0; i<k; i++) {
        init+=mod(pow(x,k-i-1)*line[i]);
        init=mod(init);
    }

    for(int i=0; i+k<=line.size(); i++) {
        h[init].push_back({idx,i});
        init=mod(x*init + M - mod(pow(x,k)*line[i]) + line[i+k]);
    }
    fen.push_back(Fenwick(line.size()));
}

void hashfind(string &line, int l, int k, ll x) {
    ll init=M;
    for(int i=0; i<k; i++) {
        init+=mod(pow(x,k-i-1)*(ll)line[i]);
        init=mod(init);
    }

    //printf("hash find: %s %d %d %lld\n", line.c_str(), l, k, x);
    for(int i=0; i+k<=line.size(); i++) {
        //printf("%s %d %lld\n", line.c_str(), i, init);
        if(h.count(init)) {
            printf("[%lld]: ", init);
            for(pii &p: h[init]) {
                int a=p.first, idx=p.second;
                //printf("a:%d L:%d R:%d\n", a,max(0,idx-l+k), idx);
                int L=max(0,idx-l+k), R=min(int(str[a].size()), idx+l)-l;
                printf("[%d](%d,%d) ",idx,L,R);
                fen[a].range_update(max(0,idx-l+k)+1, min((int)str[a].size(), idx+l)-l+1, 1LL);
            }
        } else printf("%lld ", init);
        puts("");
        init=mod(x*init + M - mod(pow(x,k)*line[i]) + line[i+k]);
    }
    puts("");
}

int main() {
    ios::sync_with_stdio(false);
    int l, k, cnt=0;
    ll x=256LL;
    printf("Input parameter L: "); cin >> l;
    printf("Input parameter K (K must be less than or equal to L): "); cin >> k;
    //printf("Input parameter x: (60 is recommended)"); cin >> x;
    if(k>l) return -1&puts("K must be less than or equal to L !!!");

    dp.resize(k+1,0LL);

    string line;
    ifstream infs("./suspicious.txt");
    puts("Suspicious Strings:");
    for(int idx=0; getline(infs, line);) {
        if(line.size()<l) continue;
        printf("%s ", line.c_str());
        str.push_back(line);
        hashing(line,l,k,x,idx);
        cnt+=line.size()-l+1;
        idx++;
    } puts("");

    //DEBUG*********************************************************************1
    auto print = [k](const string& s, int idx) {
        for(int i=0; i<k; i++) putchar(s[idx+i]);
        putchar(' ');
    };
    puts("HASH TABLE");
    for(auto &p: h) {
        printf("HASH: %lld => ",p.first);
        for(pii &c: p.second) {
            printf("(%d,%d)",c.first,c.second);
            print(str[c.first], c.second);
        } puts("");
    } puts("");
    //DEBUG*********************************************************************1

    puts("Malicious Strings:");
    ifstream infm("./malicious.txt");
    while(getline(infm, line)) {
        if(line.size()<k) continue;
        printf("** [%s]\n", line.c_str());
        hashfind(line,l,k,x);
    } puts("\n");

    auto println = [l](const string& s, int idx, ll val) {
        for(int i=0; i<l; i++) putchar(s[idx+i]);
        printf(" %lld\n", val);
    };

    puts("RESULT:");
    for(int i=0; i<str.size(); i++) {
        /*
        ll pv = fen[i].query(1), v=0;
        println(str[i],0,pv);
        //printf("%lld %lld\n",v,pv);
        for(int j=1; j+l<str[i].size(); j++) {
            //printf("str[%d].[%d] ",i,j);
            v=fen[i].query(j+1);
            println(str[i],j,v-pv);
            printf("%lld %lld\n",v,pv);
            pv=v;
        }
        */
        for(int j=0; j+l<=str[i].size(); j++) {
            println(str[i],j,fen[i].query(j+1));
        }
    }

    return 0;
}
