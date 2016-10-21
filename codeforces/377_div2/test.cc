#include <cstdio>
#include <map>
#include <vector>
using namespace std;
map<int, vector<int> > mp;
int main() {
    mp[1].push_back(2);
    mp[1].push_back(3);
    mp[3].push_back(1);
    mp[0].push_back(4);
    for(auto &p: mp) {
        printf("%d ", p.first);
        for(auto &i: p.second) {
            printf("*%d ", i);
        }
        puts("");
    }
    return 0;
}
