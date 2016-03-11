#include <cstdio>
int main() {
    long long exist, need, cnt=0, index;
    long long dist, max;
    long long arr[10000];
    long long sum=0;

    scanf("%lld %lld", &exist, &need);
    for(int i=0; i<exist; i++) {
        scanf("%lld", &arr[i]);
        sum+=arr[i];
    }
    dist=(unsigned int)(sum/need);
    if(dist==0) {
        printf("0");
        return 0;
    }

    while(1) {
        cnt=0; max=0;
        for(int i=0; i<exist; i++) {
            cnt+=arr[i]/dist;
            if(arr[i]%dist > max) {
                max=arr[i]%dist;
                index=i;
            }
        }
        if(cnt>=need) break;
        dist=arr[index]/(arr[index]/dist+1);
    }

    printf("%lld", dist);

    return 0;
}
