
// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll mod = 1e9+7;

// }}}

class PalindromicSubseq2 {
public:
    vector<pii> v;
    ll sum[3002];
    bool chk[3002];
	int solve(string s) {
        memset(chk, false, sizeof(chk));
        for(int i=0; i<s.size(); i++) sum[i]=1LL;
        for(int i=0; i<s.size(); i++) {
            char start = s[i];
            if(chk[i]) continue;
            for(int j=1; j<s.size(); j++) {
                if(start==s[j]) {
                    chk[j]=true;
                    auto it=upper_bound(v.begin(), v.end(), pii(j,i));
                    int cnt=0;
                    for(auto p=it; p!=v.end(); p++) {
                        if(p->second<i) cnt++;
                    }
                    sum[i]+=(1<<cnt);
                    sum[j+1]-=(1<<cnt);
                    v.push_back(pii(j,i));
                }
            }
        }
        for(int i=0; i<s.size(); i++) {
            sum[i+1]+=sum[i];
            //sum[i+1]%=mod;
        }
        ll res=1LL;
        for(int i=0; i<s.size(); i++) {
            res^=(((i+1)*sum[i])%mod);
        }

		return res;
	}
};

