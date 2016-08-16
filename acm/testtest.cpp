#include <cstdio>
int d[100001],  ze[400];
int main(){
#ifdef PLZRUN
    freopen("output2.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for(int i=1;i*i<=n;i++){
        ze[i]=i*i;
        d[i*i]=1;
    }
    for(int i=2;i<=n;i++){
        if(d[i]!=1){
            d[i]=d[i-ze[1]]+1;
            for(int j=2;i>ze[j];j++){
                if(d[i]>d[i-ze[j]]+1) {
                    d[i]=d[i-ze[j]]+1;
                }
            }
        }
    }
    printf("%d\n", d[n]);
    return 0;
}
