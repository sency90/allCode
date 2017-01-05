
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

class AlternatingString {
public:
    int maxLength(string s) {
        int mxcnt=0,cnt=1;
        for(int i=0; i-1<s.size(); i++) {
            if(s[i]!=s[i+1]) cnt++;
            else {
                mxcnt=max(cnt,mxcnt);
                cnt=1;
            }
        }
        return max(mxcnt,cnt);
    }
};
