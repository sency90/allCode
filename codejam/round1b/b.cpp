#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
char a[4], b[4];
struct Info {
    int dif, a, b;
    Info(int ddif, int aa, int bb) {
        dif=ddif; a=aa; b=bb;
    }
    bool operator<(const Info &rhs) const {
        if(dif == rhs.dif) {
            if(a == rhs.a) return b > rhs.b;
            else return a > rhs.a;
        } else return dif > rhs.dif;
    }
};
int spow(int x, int y) {
    int res = 1;
    for(int i=0; i<y; i++) res*=x;
    return res;
}
bool acheck(int d) {
    int n=0, t=d, r;
    while(t/=10) n++;
    t = strlen(a)-1-n;
    if(n!=strlen(a)-1) return false;
    for(int i=n; i>=0; i--) {
        r = d%10;
        d /= 10;
        if(a[i]=='?') continue;
        if(r!=a[i]-'0') return false;
    }
    /*
    for(int i=t-1; i>=0; i--) {
        if(a[i]=='?') continue;
        if(a[i]-'0'!=0) return false;
    }
    */
    return true;
}
bool bcheck(int d) {
    int n=0, t=d, r;
    while(t/=10) n++;
    t = strlen(b)-1-n;
    if(n!=strlen(b)-1) return false;
    for(int i=n; i>=0; i--) {
        r = d%10;
        d /= 10;
        if(b[i]=='?') continue;
        if(r!=b[i]-'0') return false;
    }
    /*
    for(int i=t-1; i>=0; i--) {
        if(b[i]=='?') continue;
        if(b[i]-'0'!=0) return false;
    }
    */
    return true;
}
priority_queue<Info> mnh;
vector<int> va, vb;
int main() {
    freopen("/Users/lian/allCode/codejam/round1b/bsin.txt", "r", stdin);
    freopen("/Users/lian/allCode/codejam/round1b/bsout.txt", "w", stdout);
    int t, len;
    scanf("%d", &t);
    for(int z=1; z<=t; z++) {
        va.clear();
        vb.clear();
        scanf("%s %s ", a, b);
        len = strlen(a);
        int tmp = spow(10,len);
        for(int i=0; i<tmp; i++) {
            if(acheck(i)) va.push_back(i);
            if(bcheck(i)) vb.push_back(i);
        }
        for(int i=0; i<va.size(); i++) {
            for(int j=0; j<vb.size(); j++) {
                mnh.push(Info(abs(va[i]-vb[j]), va[i], vb[j]));
            }
        }
        printf("Case #%d: %d %d\n", z, mnh.top().a, mnh.top().b);
        while(!mnh.empty()) mnh.pop();
    }
    fclose(stdin);
    return 0;
}
