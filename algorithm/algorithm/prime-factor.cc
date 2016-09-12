#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int minFactor[1000001];
    for(int i=0; i<1000001; i++) {
        minFactor[i]=i;
    }

    minFactor[0]=minFactor[1]=-1;
    for(long long i=2LL; i*i<=1000000; i++) {
        if(minFactor[i]!=i) continue; //소수가 아닌 경우
        for(long long j=i*i; j<=1000000; j+=i) {
            minFactor[j]=i;
        }
    }

    int n;
    scanf("%d", &n);
    vector<int> ret;
    //n을 소인수 분해 하면
    while(n!=1) {
        if(n%minFactor[n] == 0) ret.push_back(minFactor[n]);
        n/=minFactor[n];
    }
    sort(ret.begin(), ret.end());
    for(auto &p : ret) {
        printf("%d ", p);
    }
    puts("");
    return 0;
}
