#include <iostream>
#include <string>
using namespace std;
int chg(long long x) {
    int ret=0;
    for(int t, cnt=0; x!=0LL; cnt++, x/=10) {
        t=x%10LL;
        if(t&1) ret|=1<<cnt;
    }
    return ret;
}
int cnt[(1<<18)+1];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string type;
    int n;
    long long d;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> type >> d;
        int p = chg(d);
        if(type == "+") cnt[p]++;
        else if(type == "-") cnt[p]--;
        else printf("%d\n", cnt[p]);
    }
    return 0;
}
