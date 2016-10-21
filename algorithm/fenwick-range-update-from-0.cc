#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
struct Fenwick{
    int s,e;
    vector<int> tmul, tadd;
    Fenwick(int n):s(0),e(n-1),tmul(n),tadd(n){}
    void range_update(int left, int right, int by) {
        internal_update(left, by, -by*(left-1));
        internal_update(right, -by, by*right);
    }
    void internal_update(int at, int mul, int add) {
        for(int i=at; i<=e; i|=i+1) {
            tmul[i]+=mul;
            tadd[i]+=add;
        }
    }
    int query(int at) {
        int mul=0, add=0;
        for(int i=at; i>=0; i=(i&(i+1))-1) {
            mul+=tmul[i];
            add+=tadd[i];
        }
        return mul*at+add;
    }
};
int main() {
    Fenwick fen(5);
    fen.range_update(0,3,2);
    fen.range_update(2,4,1);
    for(int i=0; i<5; i++) {
        cout << fen.query(i) << "\n";
    }
    return 0;
}
