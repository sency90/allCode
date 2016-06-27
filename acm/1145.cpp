#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> d(5), v;
int gcd(int b, int l) {
    if(b<l) swap(b,l);
    if(b%l) return gcd(l, b%l);
    else return l;
}
int lcm(int x, int y) {
    int tmp = gcd(x, y);
    return x/tmp * y;
}
int main() {
    for(int i=0; i<5; i++) {
        scanf("%d", &d[i]);
    }
    sort(d.begin(), d.end());
    for(int i=0; i<4; i++) {
        for(int j=i+1; j<5; j++) {
            int t = lcm(d[i],d[j]);
            for(int k=0; k<5; k++) {
                if(i==k || j==k) continue;
                if(t%d[k]==0) v.push_back(t);
                else v.push_back(lcm(t,d[k]));
            }
        }
    }
    sort(v.begin(), v.end());
    printf("%d", v[0]);
    return 0;
}
