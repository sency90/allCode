
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
typedef long long ll;

// }}}

class SellingFruits {
public:
    int calc(int x, int f, int d, int p, int m) {
        int pay = m*p;
        int r = d-pay;
        return min(f+m,r/x);
    }
    int maxDays(int x, int f, int d, int p) {
        ll l=0, r=d/p;
        ll mx=min(f,d/x);
        for(int i=0; i<1000; i++) {
            ll midl = (l*2+r)/3;
            ll midr = ((r*2+l)+2)/3;
            ll resl = calc(x,f,d,p,midl);
            ll resr = calc(x,f,d,p,midr);
            mx = max(mx,resl);
            mx = max(mx,resr);
            if(resl < resr) l=midl;
            else r=midr;
        }
        return mx;
    }
};

