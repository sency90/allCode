#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int d;
    freopen("/Users/lian/allCode/acm/output2.txt", "r", stdin);
    while(scanf("%d",&d)!=EOF) {
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    freopen("/Users/lian/allCode/acm/output.txt", "w", stdout);
    for(int i=0; i<v.size(); i++) {
        printf("%d ", v[i]);
    }
    return 0;
}
