#include <stdio.h>
#include <vector>
using namespace std;
struct Fenwick{
    vector<int> tree;
    Fenwick(int n) : tree(n) {}
    int sum(int pos) {
        pos++;
        int ret = 0;
        for(int i=pos; i!=0; i&=(i-1)) {
            ret += tree[i];
        }
        return ret;
    }

    void add(int pos, int val) {
        pos++;
        for(int i=pos; i<=tree.size(); i+=(i&-i)) {
            tree[i] += val;
        }
    }
};
int main() {
    return 0;
}
