#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#define ll long long
#define left node*2
#define right node*2+1
#define mid (st+ed)/2
using namespace std;
const int MAXN=100005;
ll type[MAXN],value[MAXN],tree[MAXN*4][5],c[MAXN*4]; //tree[n][i] n번째노드가 담당하는 영역중에서 %5 한값이 i인 값들의 합
//c배열은 해당구에 들어가있는 원소의 개수
int flag; //1--> add  0-->del
void update(int node,int st,int ed,int pos,ll value){
    if(pos>ed || pos<st)return;
    flag==1 ?c[node]++:c[node]--;
    if(st==ed){
        tree[node][0]=flag*value;
        return;
    }
    update(left,st,mid,pos,value);
    update(right,mid+1,ed,pos,value);
    for(int i=0;i<5;i++)tree[node][i]=tree[left][i]+tree[right][(5-(c[left]%5)+i)%5];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    string s;
    map<ll,int> m;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="add")
            type[i]=0,cin>>value[i],m[value[i]]=-1;  //type[i]==0 add
        else if(s=="del")
            type[i]=1,cin>>value[i],m[value[i]]=-1; //type[i]==1 del
        else
            type[i]=2; //type[i]==2 sum
    }
    int ct=1;
    for(auto it=m.begin();it!=m.end();it++)it->second=ct++;
    ct--; //원소의 총개수
    for(int i=0;i<n;i++){
        if(type[i]==0)
            flag=1,update(1,1,ct,m[value[i]],value[i]);
        else if(type[i]==1)
            flag=0,update(1,1,ct,m[value[i]],value[i]);
        else
            cout<<tree[1][2]<<"\n";
    }
    return 0;
}