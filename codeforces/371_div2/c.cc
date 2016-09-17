#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int m[1<<18 + 2];
int f(long long t){
    int bina=0, cnt=0;;
    while(t != 0){
        int temp = t % 10LL;
        t /= 10LL;
        if(temp % 2 == 1) bina |= (1<<cnt);
        cnt++;
    }
    return bina;
}
int main(){
    int n;
    long long t;
    char c[2];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s %lld", c, &t);
        int temp = f(t);
        printf("%lld->%d\n",t,temp);
        if(c[0] == '+') m[temp]++;
        else if(c[0] == '-') m[temp]--;
        else printf("%d\n", m[temp]);
    }
}
