#include <stdio.h>
#include <algorithm>
using namespace std;
struct Info{
    char name[16];
    int d, m, y;

    bool operator<(const Info &rhs) const {
        if(y == rhs.y) {
            if(m == rhs.m) {
                if(d < rhs.d) return true;
                else return false;
            } else if(m < rhs.m) return true;
            else return false;
        } else if(y < rhs.y) return true;
        else return false;
    }
}info[100];
int main() {
    int n; scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        scanf("%s %d %d %d", info[i].name, &info[i].d, &info[i].m, &info[i].y);
    }
    sort(info, info+n);
    printf("%s\n%s\n",info[n-1].name, info[0].name);
    return 0;
}
