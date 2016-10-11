#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
class KiwiJuiceEasy{
public:
    vi thePouring(vi cap, vi bot, vi s, vi e) {
        for(int i=0; i<e.size(); i++) {
            bot[e[i]] += bot[s[i]];
            int r=0;
            if(cap[e[i]]<bot[e[i]]) r=bot[e[i]]-cap[e[i]];
            if(r) bot[s[i]]=r;
        }
        return bot;
    }
};
