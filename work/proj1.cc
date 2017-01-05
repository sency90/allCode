//made by plzrun. 2017.01.05 (C++14)
//Dependencies: ./suspicious.txt, ./malicious.txt
//The WORST Time Complexity: O(M(lgS)^2 + SL(lgS))
//S: the total length of suspicious.txt string
//M: the total length of malicious.txt string
//L: the parameter L
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
map<ll, vector<pii>> h; //hashmap: h[hash value] = vector{the # of line, i: the index of the line(line[i,i+k-1])}
vector<ll> dp; //dp[a] is a cache for x^a.
vector<string> str; //a storage of lines

class Fenwick{ //modified Fenwick Tree for range_update
public:
    int s,e;
    vector<ll> tree;
    Fenwick(){} Fenwick(int n):s(1),e(n),tree(n+2,0LL) {}

    //O(logN)
    void range_update(int l, int r, ll by) { //update [l,r] by adding 'by'
        internal_update(l,by);
        internal_update(r+1,-by);
    }

    //O(logN)
    ll query(int at) { //get the count[at] value
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

const ll M = 2147483629LL; //prime number for mod
ll mod(ll x) { return (x>=M)?x%M:x; }
ll pow(ll x, int a) { //to get x^a
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
    h[init].push_back({idx,0});

    for(int i=0; i+k<line.size(); i++) {
        init=mod(x*init + M - mod(pow(x,k)*line[i]) + line[i+k]);
        h[init].push_back({idx,i+1});
    }
    fen.push_back(Fenwick(line.size()));
}

void hashfind(string &line, int l, int k, ll x) {
    ll init=M;
    for(int i=0; i<k; i++) {
        init+=mod(pow(x,k-i-1)*line[i]);
        init=mod(init);
    }
    if(h.count(init)) {
        for(pii &p: h[init]) {
            int z=p.first, idx=p.second;
            int L=max(0,idx-l+k)+1, R=min(int(str[z].size()), idx+l)-l+1;
            fen[z].range_update(L,R,1LL);
        }
    }

    for(int i=0; i+k<line.size(); i++) {
        init=mod(x*init + M - mod(pow(x,k)*line[i]) + line[i+k]);
        if(h.count(init)) {
            for(pii &p: h[init]) {
                int z=p.first, idx=p.second;
                int L=max(0,idx-l+k)+1, R=min(int(str[z].size()), idx+l)-l+1;
                fen[z].range_update(L,R,1LL);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int l, k, cnt=0;
    ll x=256LL;
    printf("Input parameter L: "); cin >> l;
    printf("Input parameter K (K must be less than or equal to L): "); cin >> k;
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
    } puts("\n");

    puts("Malicious Strings:");
    ifstream infm("./malicious.txt");
    while(getline(infm, line)) {
        if(line.size()<k) continue;
        printf("%s ", line.c_str());
        hashfind(line,l,k,x);
    } puts("\n");

    auto println = [l](const string& s, int idx, ll val) {
        for(int i=0; i<l; i++) putchar(s[idx+i]);
        printf(" %lld\n", val);
    };

    puts("RESULT:");
    for(int i=0; i<str.size(); i++) {
        for(int j=0; j+l<=str[i].size(); j++) {
            println(str[i],j,fen[i].query(j+1));
        }
    }

    return 0;
}
