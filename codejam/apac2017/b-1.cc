#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#define ll long long
using namespace std;
// printf("Case #%d: %lld\n",t,sum);
bool check(long long num,long long cand){
    while(num){
        num--;
        if(num%cand)return false;
        num/=cand;
    }
    return true;
}
int main(){
    freopen("./b_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int testCase;
    scanf("%d",&testCase);
    for(int tt=1;tt<=testCase;tt++){
        ll N;
        ll num;
        scanf("%lld",&num);
        N=num;
        num--;
        set<long long> cand;
        cand.insert(num);
        for(long long i=2;i*i<=num;i++){
            if(num%i==0)cand.insert(i),cand.insert(num/i);
        }
        for(auto it=cand.begin();it!=cand.end();it++){
            long long a=*it;
            if(check(N,a)){
                printf("Case #%d: %lld\n",tt,a);
                break;
            }
        }
    }
    return 0;
}
