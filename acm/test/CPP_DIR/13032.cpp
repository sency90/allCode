#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > v;
bool cmp(const pair<int,int> &lhs, const pair<int,int> &rhs) {
    if(lhs.first == rhs.first) return lhs.second > rhs.second;
    else return lhs.first > rhs.first;
}
int d[100001];
int main() {
    int n,x,p;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&x,&p);
        v.push_back(make_pair(x,x-p));
    }
    sort(v.begin(), v.end(), cmp);

    d[0]=0;
    for(int i=0; i<v.size();) {
        for(int j=i+1; j<v.size();) {
            if(v[i].first<v[j].second) d[j++] = d[i]+1;
            else i++;
        }
    }

    int jx = v[0].second, cnt=0;
    for(int i=1; i<v.size();i--) {
        x = v[i].first;
        if(x>=jx) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
