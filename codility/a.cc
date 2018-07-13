#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
map<pii, int> pool;
int solution(vector<int> &A) {
    for(int i=0; i<A.size(); i++) {
        pii ans(0,0);
        int n = A[i];
        while(n>1) {
            if(n%2 == 0) {
                ans.first++;
                n/=2;
            } else break;
        }
        while(n>1) {
            if(n%5 == 0) {
                ans.second++;
                n/=5;
            } else break;
        }
        pool[ans]++;
    }

    int ret=0;
    for(auto it=pool.begin(); it!=pool.end(); it++) {
        int x=it->first.first, y=it->first.second;
        for(auto jt=pool.begin(); jt!=pool.end(); jt++) {
            int u=jt->first.first, v=jt->first.second;
            if(it == jt && it->second == 1) continue;
            for(auto kt=pool.begin(); kt!=pool.end(); kt++) {
                if((it==kt && it->second ==1) || ((jt==kt) && jt->second==1)) continue;
                if(it==jt && jt==kt && it->second<3) continue;
                int p=kt->first.first, q=kt->first.second;
                ret = max(ret, min(x+u+p, y+v+q));
            }
        }
    }

    return ret;
}

vector<int> v;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v.push_back(x);
    }
    printf("%d", solution(v));
}

