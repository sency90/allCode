#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
bool chk[10001];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        while(chk[v[i]]) {
            chk[v[i]]=true;
            v[i]+=k;
        }
        if(!chk[v[i]]) chk[v[i]]=true;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        if(v[i]!=i+1) return 0&puts("0");
    }
    puts("1");
    return 0;
}
