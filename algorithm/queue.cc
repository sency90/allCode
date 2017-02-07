#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Queue{
    int head, tail;
    vector<int> que;
    Queue():head(0),tail(0),que(200005){};
    void init() {head=tail=0;}
    void push(int x) { que[tail++]=x; }
    int front() { return que[head]; }
    void pop() { head++; }
    bool empty() { return head>=tail; }
    inline int size() { return tail-head; }
}q;

int main() {
    q.push(1);
    int sz = q.size();
    for(int i=0; i<sz; i++) {
        printf("%d\n", q.front());
        q.pop();
    }
}
