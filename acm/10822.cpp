#include <stdio.h>
#include <stack>
using namespace std;
stack<char> s;
int spow(int x, int y) {
    int res = 1;
    for(int i=0; i<y; i++) res *= x;
    return res;
}
int main() {
    char c;
    int sum = 0, i;
    while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
        if(c==',') {
            i=0;
            while(!s.empty()) {
                sum += s.top() * spow(10, i++);
                s.pop();
            }
            continue;
        }
        s.push(c-'0');
    }
    i=0;
    while(!s.empty()) {
        sum+= s.top()*spow(10, i++);
        s.pop();
    }
    printf("%d", sum);
    return 0;
}
