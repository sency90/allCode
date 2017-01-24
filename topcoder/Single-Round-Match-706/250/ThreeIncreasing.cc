
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

// }}}

class ThreeIncreasing {
public:
    vector<int> v;
    int minEaten(int a, int b, int c) {
        int ans=0;
        if(b>=c) {
            ans+=b-c+1;
            b=c-1;
        }
        if(a>=b) {
            ans+=a-b+1;
            a=b-1;
        }
        if(a<=0||b<=0||c<=0) ans=-1;
        return ans;
    }
};

