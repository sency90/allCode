#include <cstdio>
using namespace std;
#define N 1001
template <typename T>
struct Stack{
    int sz;
    T arr[N];
    Stack():sz(0){}
    void init() { sz=0; }
    void push(T x) { arr[sz++] = x; }
    void pop() { sz--; }
    T top() { return arr[sz-1]; }
    int size() { return sz; }
    bool empty() { return sz<=0; }
};
int main() {
    freopen("input.txt", "r", stdin);
    Stack<int> s;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        s.push(x);
    }
    while(!s.empty()) {
        printf("%d\n", s.top()); s.pop();
    }
    return 0;
}
