#include <stdio.h>
#include <cstring>
using namespace std;
const int LIM = 10000000;
int mnfc[10000001], mnfc_pwr[10000001], fcNum[10000001];
int main() {
    int t,n,l,r,p,previ;
    mnfc[0]=mnfc[1]=-1;
    for(int i=2; i<=LIM; i++) mnfc[i]=i;
    for(long long i=2LL; i*i<=LIM; i++) {
        if(mnfc[i]!=i) continue;
        for(long long j=i*i; j<=LIM; j+=i) {
            if(mnfc[j]==j) mnfc[j]=i;
        }
    }
    fcNum[1]=1;
    for(int i=2; i<=LIM; i++) {
        if(mnfc[i]==i) {
            mnfc_pwr[i]=1; fcNum[i]=2;
        } else {
            p = mnfc[i]; previ = i/p;
            if(p == mnfc[previ]) mnfc_pwr[i]=mnfc_pwr[previ]+1;
            else mnfc_pwr[i]=1;
            fcNum[i]=(fcNum[previ]/mnfc_pwr[i])*(mnfc_pwr[i]+1);
        }
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d",&n,&l,&r);
        int cnt=0;
        for(int i=l; i<=r; i++) {
            if(fcNum[i] == n) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
