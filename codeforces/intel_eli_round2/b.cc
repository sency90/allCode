#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int v[21][21];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d",&v[i][j]);
        }
    }
    vector<int> x,y;
    for(int i=0; i<m; i++) {
        for(int j=i; j<m; j++) {
            x.push_back(i);
            y.push_back(j);
        }
    }
    for(int z=0; z<x.size(); z++) {
        for(int i=0; i<n; i++) {
            swap(v[i][x[z]],v[i][y[z]]);
        }
        bool hasAns=true;
        for(int i=0; i<n; i++) {
            vector<int> tmp;
            for(int j=0; j<m; j++) {
                if(v[i][j]!=j+1) tmp.push_back(j);
            }
            if(tmp.size()==0||tmp.size()==2) continue;
            else {
                hasAns=false;
                break;
            }
        }
        if(hasAns) {
            puts("YES");
            return 0;
        }
        for(int i=0; i<n; i++) {
            swap(v[i][x[z]],v[i][y[z]]);
        }
    }
    puts("NO");
    return 0;
}
