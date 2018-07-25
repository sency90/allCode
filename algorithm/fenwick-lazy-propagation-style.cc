#include <cstdio>
using namespace std;
const int lim = 100000;
int tmul[100001], tadd[100001];
void inupdate(int at, int mul, int add) {
    for(;at<=lim;at+=at&-at) {
        tmul[at]+=mul;
        tadd[at]+=add;
    }
}
void rupdate(int l, int r, int by) {
    inupdate(l,by,-by*(l-1));
    inupdate(r,-by,by*r);
}
int query(int at) {
    int mul=0, add=0;
    for(int i=at;i;i-=i&-i) {
        mul+=tmul[i];
        add+=tadd[i];
    }
    return mul*at + add;
}
int main() {
    rupdate(2,5,3);
    rupdate(3,8,1);
    for(int i=1; i<=10; i++) {
        printf("%d ", query(i));
    }
    puts("");
    return 0;
}
