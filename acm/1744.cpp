#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> minus, plus;
bool cmp(const long long& lhs, const long long& rhs) {
    return lhs > rhs;
}
int main() {
    long long n, d;
    long long s=0;
    int ocnt = 0;
    bool zf = false;
    scanf("%lld", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &d);
        if(d<0) minus.push_back(d);
        else if(d>1) plus.push_back(d);
        else if(d==1) ocnt++;
        else zf = true;
    }
    int tmp=0, size = minus.size();
    if(size > 0) {
        sort(minus.begin(), minus.end());
        tmp = size%2;
        size -= tmp;
        for(int i=0; i+1<size; i+=2) {
            s+=minus[i]*minus[i+1];
        }
    }
    if(zf) tmp = 0;
    if(tmp) s+=minus.back();
    size = plus.size();
    if(size > 0) {
        sort(plus.begin(), plus.end(), cmp);
        tmp = size%2;
        size -= tmp;
        for(int i=0; i+1<size; i+=2) {
            s+=plus[i]*plus[i+1];
        }
        if(tmp) s+=plus.back();
    }
    if(ocnt) s+=ocnt;
    printf("%lld", s);
    return 0;
}
