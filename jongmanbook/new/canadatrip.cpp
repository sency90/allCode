#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
ll K;
int L[5001], M[5001], G[5001];
ll Count(int x) {
    ll sum=0;
    for(int i=0; i<N; i++) {
        if(L[i]-M[i]<=x && x<=L[i]) {
            sum += (int)((x-(L[i]-M[i]))/G[i])+1;
        }
        else if(L[i]<x) {
            sum += M[i]/G[i]+1;
        }
    }
    return sum;
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> N >> K;
        for(int i=0; i<N; i++) {
            cin >> L[i] >> M[i] >> G[i];
        }

        int lo=0, hi=8030100;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(Count(mid)>=K) hi=mid-1;
            else lo=mid+1;
        }
        printf("%d\n", hi+1);
    }
    return 0;
}