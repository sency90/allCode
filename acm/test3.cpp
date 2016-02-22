#include <iostream>
#include <string.h>
using namespace std;
int minmin = 0;
int order[1001][1001];
int bumo[1001];
void findvalue(int p, int *cost, int sum)
{
    for(int i=0; i<bumo[p]; i++)
        findvalue(order[p][i],cost,sum + cost[ order[p][i] ]);
    if( bumo[p] == 0)
        if( sum > minmin)
            minmin = sum;
}
int main(){
    int T;
    cin>>T;
    for(int test=0; test<T; test++)
    {
        minmin = 0;
        int N,K;
        cin>>N>>K;
        int cost[N+1];
        memset(bumo, 0 , sizeof(bumo));
        memset(order, 0, sizeof(order));
        for(int i=1; i<=N; i++)
            cin>>cost[i];
        for(int i=0; i<K; i++)
        {
            int tmp1, tmp2;
            cin>>tmp1>>tmp2;
            order[ tmp2 ][ bumo[tmp2]  ] = tmp1;
            bumo[tmp2]++; //making stacks using by arrays
        }
        int W;
        cin >> W;
        findvalue(W,cost,cost[W]);
        cout<<minmin<<endl;
    }
}
