#include <iostream>
#include <vector>
#include <string>
#define ERROR -0x3f3f3f
using namespace std;
vector<int> pi;
int kmp(const string &H, const string &N) {
    for(int i=1,m=0; i<N.size(); i++) {
        while(m!=0 && N[i]!=N[m]) m = pi[m-1];
        if(N[i]==N[m]) pi[i]=++m;
    }
    for(int i=0,m=0; i<H.size(); i++) {
        while(m!=0 && H[i]!=N[m]) m = pi[m-1];
        if(H[i]==N[m]) if(++m == N.size()) return i-(m-1);
    }
    return ERROR;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        string N, H;
        int n, ans=0;

        cin >> n >> N;
        pi.clear(); pi.resize(N.size(), 0);
        for(int i=1; i<=n; i++) {
            cin >> H;
            if(i&1) ans+=kmp(H+H,N);
            else ans+=kmp(N+N,H);
            N=H;
        }
        cout << ans << "\n";
    }
    return 0;
}
