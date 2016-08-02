#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > v;
int nv[50], state[50][50], cnt[50];
char op[51];
int main() {
    int n,m,d;
    scanf("%d%d", &n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        v.push_back(make_pair(d,i));
    }
    sort(v.begin(),v.end());
    int idx=0, pv;
    nv[v[0].second]=idx;
    pv=v[0].first;
    for(int i=1; i<m; i++) {
        if(pv==v[i].first) nv[v[i].second]=idx;
        else {
            nv[v[i].second]=++idx;
            pv=v[i].first;
        }
    }
    scanf("%s", op);
    for(int i=0; i<m; i++) {
        bool hasAns = false;
        if(op[i]=='+') cnt[nv[i]]++;
        else cnt[nv[i]]--;
        for(int j=0; j<=i; j++) {
            bool isBrk = false;
            for(int k=0; k<=idx; k++) {
                if(state[j][k]!=cnt[k]) {
                    isBrk = true;
                    break;
                }
            }
            if(!isBrk) { //break한적이 없다. => 모두 같았다.
                hasAns = true;
                break;
            }
        }

        for(int k=0; k<m; k++) {
            state[i+1][k]=cnt[k];
        }

        if(hasAns) {
            puts("0");
            return 0;
        }
    }
    puts("1");
    return 0;
}
