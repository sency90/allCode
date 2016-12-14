#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    for(int i=0; i<5; i++) v.push_back(i);
    for(int i=1; i<=5; i++) v.push_back(i);
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++) printf("%d%c",v[i]," \n"[i==v.size()-1]);
    int n = unique(v.begin(),v.end())-v.begin();
    for(int i=0; i<v.size(); i++) printf("%d%c",v[i]," \n"[i==v.size()-1]);
    for(int i=0; i<n; i++) printf("%d%c",v[i]," \n"[i==n-1]);
    printf("%d\n", n);
    return 0;
}
