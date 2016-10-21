// Fenwick Tree from 0
// update : 첫번째 0에만 +1을 해준다. at|=at+1;
// query  : 첫번째 0에만 -1을 해준다. at&=at+1; --at;
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
struct Fenwick{
    int s,e;
    vector<int> tree;
    Fenwick(int n):s(0),e(n-1),tree(n,0){}
    void update(int at, int by) {
        for(int i=at; i<=e; i|=i+1) tree[i]+=by;
    }
    int query(int at) {
        int ret=0;
        for(int i=at; i>=0; i=(i&(i+1))-1) ret+=tree[i];
        return ret;
    }
};
int main() {
    Fenwick fen(5);
    for(int i=0; i<5; i++) {
        fen.update(i,5-i);
    }
    for(int i=0; i<5; i++) {
        cout << fen.query(i) <<"\n";
    }
    return 0;
}
