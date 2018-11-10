#include <cstdio>
using namespace std;
#define N 1001
template <typename T>
struct Queue{
    int r,f;
    T arr[N];

    Queue():r(0),f(0){
        for(int i=0; i<N; i++) arr[i] = 0;
    }
    void init(){
        r=f=0;
        //for(int i=0; i<N; i++) arr[i] = 0;
    }
    void push(T x){arr[f++] = x;}
    T front() { return arr[r]; }
    void pop() { r++; }
    bool empty() { return r==f; }
    int size() { return f-r; }
};
int main() {
    freopen("input.txt", "r", stdin);
    Queue<int> q;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        q.push(x);
    }
    while(!q.empty()) {
        int x = q.front(); q.pop();
        printf("%d\n", x);
    }
    return 0;
}
