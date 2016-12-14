#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int v[501],ps,idx[501];
vector<pair<int,char> > ans;
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int m; scanf("%d",&m);
    idx[0]=-1;
    int s=0;
    for(int i=1; i<=m; i++) {
        scanf("%d", &ps);
        int sum=0;
        for(int j=s; j<n; j++) {
            sum+=v[j];
            if(sum==ps) {
                ps-=sum;
                idx[i]=j;
                s=j+1;
                break;
            } else if(sum>ps) {
                puts("NO");
                return 0;
            }
        }
    }
    if(s!=n||ps!=0) return 0&puts("NO");
    vector<pii> tmp,ori;
    for(int i=1; i<=m; i++) {
        tmp.clear();
        ori.clear();
        for(int j=idx[i-1]+1,k=0; j<=idx[i]; j++,k++) {
            tmp.push_back(make_pair(v[j],k));
        }
        while(tmp.size()>1) {
            pii mx={-1,-1};
            for(int j=0; j<tmp.size(); j++) {
                if(mx.first<tmp[j].first) {
                    mx=tmp[j];
                }
            }
            int rm=-1;
XX:
            if(mx.second==0) {
                if(tmp[mx.second+1].first < mx.first) {
                    tmp[mx.second].first+=tmp[mx.second+1].first;
                    ans.push_back({mx.second+i,'R'});
                    rm=mx.second+1;
                } else if(tmp[mx.second+1].first == mx.first) {
                    mx=tmp[mx.second+1];
                    goto XX;
                } else {
                    puts("NO");
                    return 0;
                }
            } else if(mx.second==tmp.size()-1) {
                if(tmp[mx.second-1].first < mx.first) {
                    tmp[mx.second].first+=tmp[mx.second-1].first;
                    ans.push_back({mx.second+i,'L'});
                    rm=mx.second-1;
                } else {
                    puts("NO");
                    return 0;
                }
            } else {
                if(tmp[mx.second-1].first < mx.first) {
                    tmp[mx.second].first+=tmp[mx.second-1].first;
                    ans.push_back({mx.second+i,'L'});
                    rm=mx.second-1;
                } else if(tmp[mx.second+1].first < mx.first) {
                    tmp[mx.second].first+=tmp[mx.second+1].first;
                    ans.push_back({mx.second+i,'R'});
                    rm=mx.second+1;
                } else if(tmp[mx.second-1].first==mx.first && tmp[mx.second+1].first==mx.first) {
                    mx=tmp[mx.second+1];
                    goto XX;
                } else {
                    puts("NO");
                    return 0;
                }
            }
            for(int j=0,z=0; j<tmp.size(); j++) {
                if(j==rm) continue;
                else {
                    tmp[z].first=tmp[j].first;
                    tmp[z].second=z;
                    z++;
                }
            }
            tmp.erase(tmp.end()-1);
        }
    }
    puts("YES");
    for(auto &p: ans) {
        printf("%d %c\n",p.first,p.second);
    }
    return 0;
}
