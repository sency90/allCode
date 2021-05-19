#include <stdio.h>
int a[500000];
int tmp[500000];
void merge(int s, int e) {
    int mid = (s+e)/2;
    int i=s, j=mid+1, k=0;
    while(i <= mid && j <= e) {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= e) tmp[k++] = a[j++];
    for(int q=0; q<=e-s; q++) {
        printf("%d ", tmp[q]);
    } puts("");
    for(int p=s; p<=e; p++) {
        a[p] = tmp[p-s];
    }
}
void split(int s, int e) {
    if(s == e) return;

    int mid = (s+e)/2;
    split(s, mid);
    split(mid+1, e);
    merge(s, e);
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    merge(0, n-1);
    puts("");
    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
