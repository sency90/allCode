#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<int> v;
vector<pii> g;
int main() {
    int n; scanf("%d", &n);
    int z=0, o=0;
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        if(x==0) v.push_back(-1);
        else {
            if(x%2 == 0) z++;
            else o++;
            v.push_back(x%2);
        }
    }
    int uz=n/2;
    int uo=n-uz;
    uz-=z;
    uo-=o;

    int lastOnePos=-1, lastZeroPos=-1;
    for(int i=0; i<v.size(); i++) {
        if(v[i]==1) {
            if(lastOnePos!=-1) {
                g.push_back(pii(i-lastOnePos-1, 1));
            }
            lastOnePos = i;
        }
        else {
            if(lastZeroPos!=-1) {
                g.push_back(pii(i-lastZeroPos-1,0));
            }
        }
    }

    sort(g.begin(), g.end());
    for(int i=0; i<g.size(); i++) {
        if(g[i].second == 0) {
            uz 
        }
    }



    return 0;
}
