#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int c,v0,v1,a,l;
    cin >>c>>v0>>v1>>a>>l;
    int read=0;
    for(int day=1; ; day++) {
        read+=v0;
        if(c<=read) return 0&printf("%d", day);
        v0+=a;
        if(v0>=v1) v0=v1;
        read-=l;
    }
    return 0;
}
