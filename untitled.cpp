#include <cstdio>
 
int main(){
    int t,n,a,tmp;
    float b,sum;
    scanf("%d",&t);
    while (t--) {
        tmp = 0 , sum = 0.0;
        scanf("%d",&n);
        for(int i = 0 ; i < n; i++){
            scanf("%d %f",&a,&b);
            tmp += a, sum+= (float)a*b;
        }
        sum = sum/(float)tmp;
        printf("%d %.1f", tmp, sum);
    }
}