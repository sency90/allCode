#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void f(int &x) { if(x>=120) x-=120; }
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int h,m,s,t1,t2;
    cin >> h >> m >> s >> t1 >> t2;
    h=(h*10); m=m*2; s=s*2; t1*=10; t2*=10;
    if(s!=0) h++, m++;
    if(m!=0) h++;
    f(h); f(m); f(s); f(t1); f(t2);
    bool hasAns=true;
    for(int i=t1; i!=t2; i++) {
        if(i==h||i==m||i==s) {
            hasAns=false;
            break;
        }
        if(i==119) i=-1;
    }
    if(t2==h||t2==m||t2==s) hasAns=false;
    if(hasAns) return 0&puts("YES");
    hasAns=true;
    for(int i=t1; i!=t2; i--) {
        if(i==h||i==m||i==s) {
            hasAns=false;
            break;
        }
        if(i==0) i=120;
    }
    if(t2==h||t2==m||t2==s) hasAns=false;
    if(hasAns) puts("YES");
    else puts("NO");
    return 0;
}
