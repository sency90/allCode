#include <stdio.h>
#include <stack>
using namespace std;
stack<char> a, b, res;
int main() {
    char c, t[3];
    while((c=getchar())!=' ' && c!='\n' && c!=EOF) a.push(c-48);
    while((c=getchar())!=' ' && c!='\n' && c!=EOF) b.push(c-48);

    t[2] = 0;
    while(!(a.empty() && b.empty())) {
        if(!a.empty()) {
            t[0] = a.top();
            a.pop();
        } else t[0] = 0;
        if(!b.empty()) {
            t[1] = b.top();
            b.pop();
        } else t[1] = 0;

        res.push((t[0]+t[1]+t[2])%10);
        t[2] = (t[0]+t[1]+t[2])/10;
    }
    if(t[2]!=0) res.push(t[2]);

    while(!res.empty()) {
        printf("%d", res.top());
        res.pop();
    }
    printf("\n");
    return 0;
}
