#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
set<pair<int,int> > s;
int main() {
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int x=c-a, y=d-b;
    s.insert(make_pair(e+x,f+y));
    s.insert(make_pair(e-x,f-y));
    x=e-a; y=f-b;
    s.insert(make_pair(c+x,d+y));
    s.insert(make_pair(c-x,d-y));
    x=e-c; y=f-d;
    s.insert(make_pair(a+x,b+y));
    s.insert(make_pair(a-x,b-y));

    printf("%lu\n", s.size());
    for(auto p: s) {
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}
