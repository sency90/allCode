#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v;
int main() {
    int n, d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        v.push_back(make_pair(d,i));
    }
    sort(v.begin(), v.end());
    int mx = 0;
    for(int i=0; i<n; i++) {
        if(mx < v[i].second-i) mx=v[i].second-i;
    }
    printf("%d", mx+1);
    return 0;
}
