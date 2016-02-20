#include <stdio.h>
#include <algorithm>
using namespace std;
int v[5000000];
int rIdx[5000000], lIdx[5000000];
int j, k, re;
int qSort(int n, int x, int *idx) {
    j = 0;
    k = 0;
    re = n-1;
    for(int i=0; i<re; i++) {
        if(v[idx[re]] < v[idx[i]]) { //v[i]를 오른쪽부분에 할당해야하는 경우
            rIdx[j++] = idx[i];
        } else {//v[i]를 왼쪽부분에 할당해야하는 경우
            lIdx[k++] = idx[i];
        }
    }
    if(k == x) return v[idx[re]];
    else if(k < x) {
        x -= k;
        return qSort(k, x, rIdx);
    } else {
        return qSort(j, x, lIdx);
    }
}
int main() {
    int N, K; scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &v[i]);
        rIdx[i] = N;
    }
    qSort(N, K, rIdx);
    printf("%d",v[k-1]);
    return 0;
}
