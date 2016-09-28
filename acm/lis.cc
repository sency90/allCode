#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int d;
        scanf("%d", &d);
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), d);
        if(it == v.end()) v.push_back(d);
        else *it=d;
    }
    printf("%lu\n", v.size());
    return 0;
}
