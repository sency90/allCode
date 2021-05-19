#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Info{
    int d;
    pair<int,int> co;
    Info(int dd, pair<int,int> pi) {
        d=dd; co=pi;
    }
    bool operator<(const Info &rhs) const {
        if(d == rhs.d) return co.first < rhs.co.first;
        else return d < rhs.d;
    }
};
vector<Info> v;
int diag(int x, int y) {
    return x*x+y*y;
}
int main() {
    int h, w, l;
    for(int j=2; j<=150; j++) {
        for(int i=1; i<j; i++) {
            v.push_back(Info(diag(i,j), make_pair(i,j)));
        }
    }
    sort(v.begin(), v.end());
    while(true) {
        scanf("%d %d", &h, &w);
        if(h==0 && w==0) return 0;
        l = diag(h,w);
        for(int i=0; i<v.size(); i++) {
            if(v[i].d < l) continue;
            else if(v[i].d == l) {
                if(v[i].co.first > h) {
                    printf("%d %d\n", v[i].co.first, v[i].co.second);
                    break;
                }
            } else {
                printf("%d %d\n", v[i].co.first, v[i].co.second);
                break;
            }
        }
    }
    return 0;
}
