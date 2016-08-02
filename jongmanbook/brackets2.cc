#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std;
char str[10001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        stack<int> s;
        scanf("%str", str);
        int len = strlen(str);
        bool hasAns = true;
        for(int j=0; j<len; j++) {
            if(str[j]=='(' || str[j]=='{' || str[j]=='[') s.push(str[j]);
            else {
                if(s.empty()) {
                    hasAns = false;
                    break;
                }
                if(str[j]==')') {
                    if(s.top()=='(') s.pop();
                    else {
                        hasAns = false;
                        break;
                    }
                } else if(str[j]=='}') {
                    if(s.top()=='{') s.pop();
                    else {
                        hasAns = false;
                        break;
                    }
                } else if(str[j]==']') {
                    if(s.top()=='[') s.pop();
                    else {
                        hasAns = false;
                        break;
                    }
                } else {
                    hasAns = false;
                    break;
                }
            }
        }
        if(hasAns && s.empty()) puts("YES");
        else puts("NO");
    }
    return 0;
}
