#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
struct Fenwick{
    int s,e;
    vector<int> tmul, tadd;
    Fenwick(int n):s(1),e(n),tmul(n+1),tadd(n+1){}
    void range_update(int left, int right, int by) {
        internal_update(left, by, -by*(left-1));
        internal_update(right, -by, by*right);
    }
    void internal_update(int at, int mul, int add) {
        for(int i=at; i<=e; i+=i&-i) {
            tmul[i]+=mul;
            tadd[i]+=add;
        }
    }
    int query(int at) {
        int mul=0, add=0;
        for(int i=at; i>=1; i-=i&-i) {
            mul+=tmul[i];
            add+=tadd[i];
        }
        return mul*at+add;
    }
};
int main() {
    Fenwick fen(5);
    fen.range_update(1,4,2);
    fen.range_update(3,5,1);
    for(int i=1; i<=5; i++) {
        cout << fen.query(i) << "\n";
    }
    return 0;
}
