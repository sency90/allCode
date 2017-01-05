#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef vector<string> vs;
class InterestingParty{
public:
    map<string, int> cnt;
    vs first, second;
    int n,mx=0;
    void dfs(int x) {
        if(x==n) {
            for(auto &p : cnt) {
                mx = max(mx,p.second);
            }
            return;
        }
        cnt[first[x]]++;
        dfs(x+1);
        cnt[first[x]]--;

        cnt[second[x]]++;
        dfs(x+1);
        cnt[second[x]]--;
    }
    int bestInvitation(vs first, vs second) {
        this->first=first; this->second=second;
        dfs(0);
        return mx;
    }
};

