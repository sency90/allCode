#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ms, ps;
bool cmp(const int& lhs, const int& rhs) {
    return lhs > rhs;
}
int main() {
    int n, d, zf=false, one=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        if(d==0) zf = true;
        else if(d==1) one++;
        else if(d>1) ps.push_back(d);
        else ms.push_back(d);
    }
    sort(ps.begin(), ps.end(), cmp);
    sort(ms.begin(), ms.end());
    int len=0, r=0;
    long long sum=0LL;
    if(ps.size()%2 == 1) {
        len = ps.size()-1;
        sum += ps[len];
    } else len = ps.size();
    for(int i=0; i<len; i+=2) {
        sum += ps[i]*ps[i+1];
    }
    if(ms.size()%2 == 1) {
        len = ms.size()-1;
        r = ms[len];
    } else len = ms.size();
    for(int i=0; i<len; i+=2) {
        sum += ms[i]*ms[i+1];
    }
    if(zf) printf("%lld", sum+one);
    else printf("%lld", sum+r+one);
    return 0;
}
