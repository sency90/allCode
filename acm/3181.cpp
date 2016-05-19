#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
queue<int> q;
char base[][5]={"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
char s[101], c;
int main() {
    bool isBrk, isFirst=true;
    while(scanf("%s", s)!=EOF) {
        if(isFirst) {
            isFirst = false;
            q.push(s[0]-'a'+'A');
        } else {
            isBrk = false;
            for(int i=0; i<10; i++) {
                if(!strcmp(base[i], s)) {
                    isBrk = true;
                    break;
                }
            }
            if(isBrk) continue;
            q.push(s[0]-'a'+'A');
        }
    }
    while(!q.empty()) {
        printf("%c", q.front());
        q.pop();
    }
    return 0;
}
