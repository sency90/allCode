#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
struct Tree{
    Tree *l, *r;
    Tree():l(NULL),r(NULL){}
};
Tree *root;
void mktree(ll k) {
    while(k>=1) {
        if(k&1LL) {
            k/=2LL;
            Tree *t = new Tree();
            t->r = root;
            root = t;
        } else {
            k/=2LL;
            Tree *t = new Tree();
            t->l = root;
            root = t;
        }
        //if(k==0LL) break;
    }
}
pair<ll,ll> dfs(ll x) {
    while((root->l!=NULL || root->r!=NULL)) {
        if(root->l!=NULL) {
            root=root->l;
            x=(x-1)-(x-1)/2LL;
        } else {
            root=root->r;
            x=(x-1)/2LL;
        }
    }
    ll l=x-1-(x-1)/2LL, r=(x-1)/2LL;
    return pair<ll,ll>(l,r);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int tc; cin >> tc;
    for(int z=1; z<=tc; z++) {
        ll n,k; cin >> n >> k;
        Tree *tr = new Tree();
        root = tr;
        mktree(k);
        pair<ll,ll> ans = dfs(n);
        printf("Case #%d: %lld %lld\n",z, ans.first, ans.second);
    }
    return 0;
}
