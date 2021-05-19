#include <stdio.h>
#include <vector>
using namespace std;
struct Info{
    int x, y;
    Info(int xx, int yy) {
        x=xx; y=yy;
    }
};
vector<Info> v;
char tmp[101];
bool f(Info& a, Info& b, Info& c) {
    if(a.x*b.y + b.x*c.y + c.x*a.y == b.x*a.y + c.x*b.y + a.x*c.y) return true;
    else return false;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", tmp);
        for(int j=0; j<n; j++) {
            if(tmp[j]!='.') v.push_back(Info(i,j));
        }
    }
    long long cnt = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            for(int k=j+1; k<v.size(); k++) {
                if(f(v[i],v[j],v[k])) cnt++;
            }
        }
    }
    printf("%lld", cnt);
    return 0;
}
