#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;
bool vnv(int x) {
    v.clear();
    while(x!=0) {
        v.push_back(x%10);
        x/=10;
    }
    int d = v[1]-v[0];
    bool good = true;
    for(int i=2; i<v.size(); i++) {
        if(d != v[i]-v[i-1]) {
            good = false;
            break;
        }
    }
    if(good) return true;
    else return false;
}
int main() {
    int n;
    scanf("%d",&n);
    if(n<100) printf("%d", n);
    else {
        int cnt = 99;
        for(int i=100; i<=n; i++) {
            if(vnv(i)) cnt++;
        }
        printf("%d", cnt);
    }
    return 0;
}
