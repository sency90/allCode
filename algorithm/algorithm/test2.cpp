#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
map<int,int> m;
int main() {
    m[7]=7;
    m[10]=10;
    map<int,int>::iterator it = m.upper_bound(8);
    printf("%d %d\n", it->first, it->second);
    map<int,int>::iterator it2 = m.lower_bound(8);
    printf("%d %d\n", it2->first, it2->second);
    return 0;
}
