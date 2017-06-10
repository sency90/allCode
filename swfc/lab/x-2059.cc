#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
        if(it==v.end()) v.push_back(x);
        else *it=x;
    }
    printf("%d\n", n-int(v.size()));
    return 0;
}
