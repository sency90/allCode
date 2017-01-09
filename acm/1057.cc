#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[2];
int main() {
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1; i<=n; i++) v[0].push_back(i);
    for(int r=1, t=0; ;r++, t^=1) {
        v[t^1].clear();
        for(int i=0; i<v[t].size(); i+=2) {
            if(i+1==v[t].size()) {
                v[t^1].push_back(v[t][i]);
                continue;
            }
            if(v[t][i]==a&&v[t][i+1]==b) return 0&printf("%d",r);
            else if(v[t][i]==b&&v[t][i+1]==a) return 0&printf("%d",r);
            else if(v[t][i]==a||v[t][i+1]==a) v[t^1].push_back(a);
            else if(v[t][i]==b||v[t][i+1]==b) v[t^1].push_back(b);
            else if(v[t][i]!=a&&v[t][i]!=b&&v[t][i+1]!=a&&v[t][i+1]!=b) v[t^1].push_back(v[t][i]);
        }
    }
    return 0;
}
