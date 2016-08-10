#include <cstdio>
#include <vector>
using namespace std;
vector<int> c, g;
int x, y;
int main() {
    for(int i=1; i<=6; i++) {
        c.push_back(i);
    }
    g.push_back(0);
    for(int i=1; i<=4; i++) {
        g.push_back(i+0.3);
        g.push_back(i);
        g.push_back(i-0.3);
    }
    int seed=0, lim=6*g.size();
    for(int i=1; i<=10; i++) {
        printf("%d\n", i);
        for(int k=0; k<i; k++) {
            printf("%d %d\n", c[x++%6], g[y++%g.size()]);
        }
    }
    return 0;
}
