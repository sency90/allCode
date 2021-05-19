#include <stdio.h>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
struct S{
    int x;
    bool operator>(const S& rhs) const {
        return x > rhs.x;
    }
};
priority_queue<S, vector<S>, greater<S> > minheap;
int main() {
    S s;
    int n; scanf("%d", &n);
    while(n--) {
        scanf("%d", &s.x);
        minheap.push(s);
    }
    while(!minheap.empty()) {
        printf("%d\n", minheap.top().x);
        minheap.pop();
    }
    return 0;
}
