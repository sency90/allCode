#include <stdio.h>
#include <stack>
#include <map>
using namespace std;
stack<int> s;
//a,g,c,t
int m[4][4]={{0,2,0,1},{2,1,3,0},{0,3,2,1},{1,0,1,3}};
int main() {
    int n, pc, ppc;
    char c;
    scanf("%d ", &n);
    while((c=getchar())!='\n' && c!=EOF && c!='\r') {
        if(c=='A') s.push(0);
        else if(c=='G') s.push(1);
        else if(c=='C') s.push(2);
        else s.push(3);
    }
    ppc = s.top(); s.pop();
    while(!s.empty()) {
        pc = s.top(); s.pop();
        ppc=m[pc][ppc];
    }
    if(ppc == 0) putchar('A');
    else if(ppc == 1) putchar('G');
    else if(ppc == 2) putchar('C');
    else putchar('T');
    return 0;
}
