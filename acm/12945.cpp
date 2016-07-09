#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
bool chk[500001];
vector<int> w;
vector<int>::iterator it;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());

    vector<int> l(v.begin(), v.begin()+v.size()/2);
    vector<int> r(v.begin()+v.size()/2, v.end());

    int cnt=0;
    for(int i=l.size()-1, j=r.size()-1; i>=0 && j>=0; i--) {
        if(2*l[i] <= r[j]) {
            j--; cnt++;
        }
    }
    printf("%lu\n",l.size()-cnt+r.size());
    return 0;
}
