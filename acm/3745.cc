#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<int>::iterator it;
int main() {
    int n,d;
    while(~scanf("%d", &n)) {
        vector<int> v;
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            it = lower_bound(v.begin(), v.end(), d);
            if(it==v.end()) v.push_back(d);
            else *it=d;
        }
        printf("%lu\n", v.size());
    }
    return 0;
}
