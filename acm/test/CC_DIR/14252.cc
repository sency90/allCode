#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int gcd(int b, int s) {
    return (s==0)?b:gcd(s,b%s);
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int cnt=0;
    for(int i=0; i<v.size()-1; i++) {
        if(gcd(v[i],v[i+1])!=1) {
            bool good=false;
            for(int j=v[i]+1; j<v[i+1]; j++) {
                if(gcd(v[i],j)==1 && gcd(j,v[i+1])==1) {
                    good=true;
                    break;
                }
            }
            if(good) cnt++;
            else cnt+=2;
        }
    }
    printf("%d", cnt);
    return 0;
}
