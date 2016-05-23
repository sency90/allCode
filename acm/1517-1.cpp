#include <stdio.h>
int a[500001], tmp[500001];
long long cnt = 0;
void merge(int s, int e) {
    int mid = (s+e)/2;
    int i=s, j=mid+1, k=0;
    while(i<=mid && j<=e) {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            cnt += (long long)(mid-i+1);
        }
    }
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=e) tmp[k++] = a[j++];
    for(int l=s; l<=e; l++) {
        a[l] = tmp[l-s];
    }
}
void msort(int s, int e) {
    if(s == e) return;
    int mid = (s+e)/2;
    msort(s, mid);
    msort(mid+1, e);
    merge(s, e);
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    msort(0, n-1);
    printf("%lld", cnt);
    return 0;
}
