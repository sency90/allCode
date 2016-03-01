#include <stdio.h>
#include <algorithm>
using namespace std;
int v[5000000];
int rIdx[5000000], lIdx[5000000];
int j, re, l;
int qSort(int n, int k, int *idx) {
    j = 0;
    l = 0;
    re = n-1;
    for(int i=0; i<re; i++) {
        if(v[idx[re]] < v[idx[i]]) { //v[i]를 오른쪽부분에 할당해야하는 경우
            rIdx[j++] = idx[i];
        } else {//v[i]를 왼쪽부분에 할당해야하는 경우
            lIdx[l++] = idx[i];
        }
    }
    if(l == k) return v[idx[re]];
    else if(l < k) {
        k -= l;
        return qSort(j, k-1, rIdx);
    } else {
        return qSort(l, k, lIdx);
    }
}
int main() {
    int n, k; scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        rIdx[i] = i;
    }
    printf("%d", qSort(n, k-1, rIdx));
    return 0;
}
