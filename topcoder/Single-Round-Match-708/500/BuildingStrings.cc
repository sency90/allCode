
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

typedef long long ll;
using namespace std;

// }}}

vector<string> res;

class BuildingStrings {
    public:
        vector <string> findAny(int K) {
            int k=K;
            for(ll i=26; i>0; i--) {
                string s="";
                if(k>=i*i) {
                    for(int j=0; j<i; j++) s+=(char)('a'+j);
                    k -= i*i;
                    while(k>=i*i) {
                        s+="a";
                        k-=i;
                        if(s.size() == 50) break;
                    }
                    res.push_back(s);
                    if(k>i*i)i++;
                }
            }
            return res;
        }
};
