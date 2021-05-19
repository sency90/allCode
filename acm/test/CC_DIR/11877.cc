#include <iostream>
using namespace std;
bool chk[1000001];
int main() {
    ios::sync_with_stdio(false);
    long long n, x;
    cin >> n >> x;
    if(n==1LL) {
        if(x==0LL) cout << "1";
        else cout << "-1";
        return 0;
    }
    if(x>(n-1LL)*(n-2LL)/2LL) {
        cout << "-1";
        return 0;
    }

    int h = n-1;
    cout << h << " ";
    for(int i=h-1; i>=1; i--) {
        if(x>=i) {
            cout << h-i << " ";
            chk[h-i] = true;
            x-=i;
        } else {
            if(x==0LL) break;
            else i=x+1;
        }
    }
    cout << h+1 << " ";

    for(int i=n-2; i>=1; i--) {
        if(!chk[i]) cout << i << " ";
    }
    return 0;
}
