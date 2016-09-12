#include <iostream>
#include <algorithm>
using namespace std;
int spow(int x) {
    if(x==0) return 1;
    int ret = spow(x/2);
    if(x%2) return ret*ret*2;
    else return ret*ret;
}
int getSize(int x) {
    int cnt=0;
    while(x>0) {
        x/=2;
        cnt++;
    }
    return spow(cnt+1)+1;
}
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << getSize(n);
    return 0;
}
