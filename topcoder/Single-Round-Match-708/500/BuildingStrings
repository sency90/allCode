
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

class BuildingStrings {
    public:
        vector <string> findAny(int K) {
            vector<string> v;
            string bs="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx";
            string ss="abcdefghijklmnopqrstuvwxyz";
            string s100="abcdeabcdeabcdeabcde";

            string s50;
            for(int i=0; i<50; i++) s50+='a';
            while(K>=1300) {
                K-=1300;
                v.push_back(bs);
            }
            while(K>=676) {
                K-=676;
                v.push_back(ss);
            }
            while(K>=100) {
                K-=100;
                v.push_back(s100);
            }
            while(K>=50) {
                K-=50;
                v.push_back(s50);
            }
            if(K!=0) {
                string tmp;
                for(int i=0; i<K; i++) tmp+='a';
                v.push_back(tmp);
            }
            return v;
        }
};

