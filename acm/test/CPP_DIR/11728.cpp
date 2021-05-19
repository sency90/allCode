#include <stdio.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int> > minheap;
int main() {
    int n, m, x, len;
    scanf("%d %d", &n, &m);
    len = n+m;
    for(int i=0; i<len; i++) {
        scanf("%d", &x);
        minheap.push(x);
    }
    while(!minheap.empty()) {
        printf("%d ", minheap.top());
        minheap.pop();
    }
}
