//made by plzrun. 2017.01.05 (C++14)
//Input Files: ./string.txt, ./dictionary.txt
//Output File: ./output_proj2.txt
//The WORST Time Complexity: O(D+SlgS)
//S: the total length of string.txt
//D: the total length of dictionary.txt
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
const ll M = 2147483629LL;
map<ll, int> h; //hashmap
vector<string> str;
vector<ll> dp; //dp[a] is a cache for x^a.

ll mod(ll x) { return (x>=M)?x%M:x; }
ll pow(ll x, int a) {
    ll &ret = dp[a];
    if(ret) return ret;
    if(a==0) return ret = 1LL;

    ret = mod(pow(x,a>>1)*pow(x,a>>1));
    if(a&1) return ret=mod(ret*x);
    else return ret;
}
void hashing(string &line, int idx, ll x) {
    ll init=M;
    int sz = line.size();
    for(int i=0; i<sz; i++) {
        init += mod(pow(x,sz-i-1))*line[i];
        init = mod(init);
    }

    if(h.count(init)) {
        if(str[h[init]]!=line) {
            puts("Collision Occured!!\n");
            puts("Please restart this program and input another parameter 'x'\n");
            return;
        } else {
            puts("Caution!! This Dictionary is not consisted of distinct strings!!");
            printf("#%d, #%d lines are conflicting.\n", h[init], idx);
        }
    } else h[init]=idx;
}

vector<int> v, lis, parent;
void hashfind(string &line, int sz, ll x) {
    ll init=M;
    for(int i=0; i<sz; i++) {
        init += mod(pow(x,sz-i-1))*line[i];
        init = mod(init);
    }

    if(h.count(init)) v.push_back(h[init]);
    for(int i=0; i+sz<line.size(); i++) {
        init = mod(x*init + M - mod(pow(x,sz)*line[i]) + line[i+sz]);
        if(h.count(init)) v.push_back(h[init]);
    }
}
int main() {
    string line;
    ll x=256LL; //the parameter x of Rabin-Karp fingerprinting
    ifstream infd("./dictionary.txt");
    int sz=0;
    for(int i=0; getline(infd, line); i++) {
        if(!i) {
            dp.resize(line.size()+1, 0LL);
            sz = line.size();
        } else if(sz != line.size()) {
            return 0&puts("The length of Dictionary words must be equal to each other.\n");
        }
        str.push_back(line);
        hashing(line, i, x);
    }

    ifstream infs("./string.txt");
    getline(infs, line);
    hashfind(line, sz, x);

    parent.resize(v.size());
    int start = -1;
    for(int p: v) {
        auto it = lower_bound(lis.begin(), lis.end(), p);
        if(it == lis.begin()) parent[p]=start;
        else parent[p]=*(it-1);

        if(it == lis.end()) lis.push_back(p);
        else *it = p;
    }

    stack<int> st;
    for(int i=lis.back();i!=-1;i=parent[i]) st.push(i);

    FILE *fout = fopen("./output_proj2.txt", "w");
    while(!st.empty()) {
        fprintf(fout, "%s\n", str[st.top()].c_str());
        st.pop();
    }
    printf("'./output_proj2.txt' has been made successfully!\n");
    return 0;
}
