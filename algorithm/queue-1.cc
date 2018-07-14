#include <cstdio>
#define SHIFT 17
using namespace std;
struct Queue{
    const int sz = (1<<SHIFT)-1;
    int head, tail;
    int v[(1<<SHIFT)+1];
    Queue():head(0),tail(0){}
    void clear() { head = tail = 0; }
    int size() { return tail<head?sz+tail-head:tail-head; }
    void push(int x) {
        if(tail>>SHIFT) {
            tail>>=SHIFT;
            if(tail==head) puts("error");
        }
        v[tail++]=x;
    }
    int front() { return v[head]; }
    void pop() {
        if(head==tail) puts("error");
        if(++head>sz) head>>=SHIFT;
    }
    bool empty() { return head==tail; }
};
int main() {
    return 0;
}
