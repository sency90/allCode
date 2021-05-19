#include<cstdio>
#include<vector>
#include<algorithm>
 
int a[11111];
int b[11111];
std::vector<int> g[11111],r;
 
void dfs(int x,int y)
{
    int i;
    for(i=0;i<g[x].size();i++)if(g[x][i]!=y)
    {
        dfs(g[x][i],x);
        a[x]+=b[g[x][i]];
        b[x]+=std::max(a[g[x][i]],b[g[x][i]]);
    }
}
 
void prt(int x,int y,int z)
{
    int i;
    if(z)r.push_back(x);
    for(i=0;i<g[x].size();i++)if(g[x][i]!=y)prt(g[x][i],x,!z&&a[g[x][i]]>b[g[x][i]]);
}
 
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    while(--n)
    {
        scanf("%d%d",&i,&j);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    dfs(1,0);
    printf("%d\n",std::max(a[1],b[1]));
    prt(1,0,a[1]>b[1]);
    std::sort(r.begin(),r.end());
    for(i=0;i<r.size();i++)printf("%d ",r[i]);
}