#include <cstdio>
using namespace std;
int v[16] = {13, 3, 6, 4, 1, 12, 2, 5, 9, 10, 14, 15, 8, 7, 11};
int buf[16];

void msort(int *arr, int s, int e) {
    if (s+1 >= e) return;
    int m = (s + e) / 2;
    msort(arr, s, m);
    msort(arr, m, e);

    int i = s, j = m, k=s;
    while(i<m && j<e) {
        if(arr[i]<arr[j]) buf[k++]=arr[i++];
        else buf[k++] = arr[j++];
    }
    while(i<m) buf[k++] = arr[i++];
    while(j<e) buf[k++] = arr[j++];
    for(i=s; i<e; i++) arr[i] = buf[i];
}
int main()
{
    puts("before:");
    for(int i=0; i<16; i++) {
        printf("%2d ", v[i]);
    }
    puts("\n");
    msort(v, 0, 16);
    puts("after:");
    for(int i=0; i<16; i++) {
        printf("%2d ", v[i]);
    }
    return 0;
}