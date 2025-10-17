/* 알고리즘 과제 22011122361 정수영*/ 

#include <cstdio>

#define max(a,b) ((a)>(b) ? (a): (b))

using namespace std;

int main()
{
    int n; scanf("%d",&n);
    int arr[1001];
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
    int k=0;
    int cnt;
    for(int i=0; i<=n; i++){
        cnt=0;
        for(int j=1; j<=n; j++){
            if(arr[j]>=i) cnt++;
        }
        if(i<=cnt) {
           k=max(i,k);
        }
    }

    printf("%d",k);

    return 0;
}
