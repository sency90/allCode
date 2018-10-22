#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> arr;
int main() {
    int l,r,N,Q;

    //N: the number of arr[]
    //Q: the number of queries
    scanf("%d %d", &N, &Q);
    arr.resize(N+1);

    int at, by;
    while(Q--) {
        //update
        scanf("%d %d", &at, &by);
        assert(1<=at && at<=N);
        arr[at]+=by;

        //query sum[l,r]
        int sum=0;
        scanf("%d %d", &l, &r);
        for(int i=l; i<=r; i++) {
            sum += arr[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}
