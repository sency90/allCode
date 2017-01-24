#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,k;
ll sum(ll l, ll r) {
    if(l==r) return l;
    return r*(r+1)/2-l*(l-1)/2;
}
bool chk(ll p) {
    ll left, right;
    if(k-p<1) left=sum(p-k+1,p);
    else left=sum(1,p)+k-p;
    if(n-k<p) {
        right = sum(p-(n-k),p-1);
    } else {
        right = sum(1,p-1)+n-(p+k)+1;
    }
    if(right+left>m) {
        return true;
    }
    return false;

}
int main() {
    cin >> n >> m >> k;
    if(n==1) {
        cout << m;
        return 0;
    }
    ll l=1, r=0x3f3f3f3f;
    while(r-l>1) {
        ll m=(r+1)/2;
        if(chk(m)) r=m;
        else l=m;
    }
    cout <<l;
    cin >>n;
    return 0;
}
