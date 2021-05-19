#include <stdio.h>
#include <stack>
#include <ctype.h>
using namespace std;
stack<char> s;
int b;
int bf(int x) {
    int res = 1;
    for(int i=0; i<x; i++) res *= b;
    return res;
}
int chg(char c) {
    if(isdigit(c)) return c-'0';
    else return c+10-'A';
}
int main() {
    char c;
    int i=0, res = 0;
    while((c=getchar())!=' ' && c!='\n' && c!=EOF) {
        s.push(c);
    } scanf("%d", &b);
    while(!s.empty()) {
        res += chg(s.top())*bf(i++);
        s.pop();
    }
    printf("%d", res);
    return 0;
}
