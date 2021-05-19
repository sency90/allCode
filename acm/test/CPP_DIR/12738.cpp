#include <cstdio>
#include <vector>
#include <algorithm>
std::vector<int> v;
std::vector<int>::iterator it;
int main() {
    int n,d;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&d);
        it = std::upper_bound(v.begin(), v.end(), d);
        if(it==v.end()) v.push_back(d);
        else *it=d;
    } printf("%lu",v.size());
}
