#include <cstdio>
#include <iostream>
using namespace std;
long long v[501][501];
pair<long long, long long> pos;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> v[i][j];
            if(!v[i][j]) pos = make_pair(i,j);
        }
    }

    int sum=0, wsum=0, rem=0;
    bool hasAns = false;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==pos.first && j==pos.second) {
                sum = 0;
                hasAns = false;
                break;
            }
            sum+=v[i][j];
        }
        if(hasAns) break;
    }

    for(int i=0; i<n; i++) wsum += v[i][pos.second];

    printf("%d", sum-wsum);

    return 0;
}
