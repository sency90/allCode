#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
vector<int> w;
int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        v.push_back(pii(x,y));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        vector<int>::iterator it = upper_bound(w.begin(), w.end(), v[i].second);
        if(it == w.end()) w.push_back(v[i].second);
        else *it = v[i].second;
    }
    printf("%d\n", n-w.size());
    return 0;
}
