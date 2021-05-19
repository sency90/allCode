#include <cstdio>
#include <bitset>
#include <set>
#include <cstring>
using namespace std;
typedef bitset<4> b4;
set<unsigned long> validNextBit[1<<4];
int d[101][1<<4];
void setBit(b4 before, b4 after, int pos) {
    //base case
    if(pos==4) {
        validNextBit[before.to_ulong()].insert(after.to_ulong());
        return;
    }

    if(!before.test(pos)) setBit(before,after.set(pos),pos+1);
    else setBit(before,after,pos+1);
    if(pos<3 && before.test(pos)==before.test(pos+1)) setBit(before, after.set(pos).set(pos+1), pos+2);
}
int solve(int n, b4 s) {
    if(n==-1) {
        if(s.all()) return 1LL;
        else return 0LL;
    }

    int &ret = d[n][s.to_ulong()];
    if(ret != -1) return ret;
    else ret = 0;
    for(auto &ns : validNextBit[s.to_ulong()]) {
        ret += solve(n-1, ns);
    }
    return ret;
}
int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<16; i++) setBit(i,0,0);
    while(tc--) {
        int n;
        memset(d,-1,sizeof(d));
        scanf("%d", &n);
        printf("%d\n",solve(n,0));
    }
    return 0;
}
