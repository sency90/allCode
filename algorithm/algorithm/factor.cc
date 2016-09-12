#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

struct SetF {
    vector<int> v;
    void print() {
        for(const auto &p : v) printf("%d ", p);
        puts("");
    }
};
SetF factor(int n) {
    SetF fc;
    stack<int> s;

    for(int j=1; j*j<=n; j++) {
        if(n%j == 0) fc.v.push_back(j);
        if(n/j != j) s.push(n/j);
    }
    while(!s.empty()) {
        fc.v.push_back(s.top());
        s.pop();
    }
    return fc;
}
int main() {
    int n;
    scanf("%d", &n);
    SetF fc = factor(n);
    fc.print();
    return 0;
}
