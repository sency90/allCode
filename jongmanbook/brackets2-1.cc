#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
char str[10001];
char open[]="{([", close[]="})]";
int f() {
    stack<int> s;
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        for(int j=0; j<3; j++) {
            if(str[i] == open[j]) {
                s.push(j);
            }
        }
        for(int j=0; j<3; j++) {
            if(str[i] == close[j]) {
                if(s.empty()) return false;
                else if(s.top() == j) s.pop();
                else return false;
            }
        }
    }
    if(s.empty()) return true;
    else return false;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        scanf("%s", str);
        if(f()) puts("YES");
        else puts("NO");
    }
    return 0;
}
