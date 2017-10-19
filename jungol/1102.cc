#include <stdio.h>
char str[2];
struct Stack{
    int v[1001];
    int sz=0;
    inline void push(int x) { v[sz++]=x; }
    inline int pop() { return v[--sz]; }
    inline bool empty() { return sz==0; }
    inline int size() { return sz; }
};
Stack s;
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s",str);
        if(str[0]=='i') {
            int val; scanf("%d",&val);
            s.push(val);
        } else if(str[0]=='c') printf("%d\n",s.size());
        else {
            if(!s.empty()) printf("%d\n",s.pop());
            else puts("empty");
        }
    }
    return 0;
}
