#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<unsigned long> v;
vector<unsigned long>::iterator it;
int main() {
    unsigned long n, d;
    scanf("%lu", &n);
    for(unsigned long i=0; i<n; i++) {
        scanf("%lu", &d);
        it = lower_bound(v.begin(), v.end(), d);
        if(it == v.end()) v.push_back(d);
        else *it = d;
    }
    printf("%lu", v.size());
    return 0;
}
