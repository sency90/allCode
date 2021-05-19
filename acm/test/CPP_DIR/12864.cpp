#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<double, int> > v;
int w[5001], nv[5001], d[5001];
int main() {
    int n;
    double x;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lf", &x);
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(), v.end());

    int sum=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &w[i]);
        d[i]=w[i];
        sum+=w[i];
        nv[v[i].second]=i;
    }

    int mx=0;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(nv[i]<nv[j]) d[j]=max(d[j],d[i]+w[j]);
            if(mx < d[j]) mx=d[j];
        }
    }

    printf("%d", sum-mx);
    return 0;
}
