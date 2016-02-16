#include <stdio.h>
#include <stack>
using namespace std;
stack<int> s;

int main() {
    int cnt = 0, res = 0, temp;
    char c;

    while((c=getchar())!='\n' && c!=EOF) {
        cnt++;
        if(c == '(') {
            s.push(cnt);
        } else if(c == ')') {
            temp = s.top();
            s.pop();
            if(temp == cnt-1) res += s.size();
            else res++;
        }
    }
    printf("%d\n", res);

    return 0;
}
