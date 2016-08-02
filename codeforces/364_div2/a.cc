#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> > v;
int main() {
    int n,d;
    scanf("%d", &n);
    int sum=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        v.push_back(make_pair(d,i));
        sum += d;
    }
    sort(v.begin(), v.end());
    int tmp = n/2;
    for(int i=0; i<tmp; i++) {
        printf("%d %d\n", v[i].second+1, v[n-1-i].second+1);
    }
    return 0;
}
