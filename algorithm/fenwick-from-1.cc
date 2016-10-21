// Fenwick Tree from 1
// update : 첫번째 1에만 +1을 해준다. at+=at&-at;
// query  : 첫번쨰 1에만 -1을 해준다. at-=at&-at;
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
struct Fenwick{
    int s,e;
    vector<int> tree;
    Fenwick(int n):s(1),e(n),tree(n+1){}
    void update(int at, int by){
        for(int i=at; i<=e; i+=i&-i) tree[i]+=by;
    }
    int query(int at) {
        int ret=0;
        for(int i=at; i>=1; i-=i&-i) ret+=tree[i];
        return ret;
    }
};
int main() {
    Fenwick fen(5);
    for(int i=1; i<=5; i++) {
        fen.update(i,6-i);
    }
    for(int i=1; i<=5; i++) {
        cout << fen.query(i) << "\n";
    }
    return 0;
}
