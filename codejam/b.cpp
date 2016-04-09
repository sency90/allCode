#include <stdio.h>
#include <queue>
using namespace std;
int main() {
    int t, cnt;
    char c;
    scanf("%d ", &t);
    for(int k=1; k<=t; k++) {
        cnt = 0;
        queue<char> q;
        while((c=getchar())!='\n' && c!=EOF) {
            q.push(c);
        }
        bool everMinus = false, everPlus = false;
        while(!q.empty()) {
            c = q.front(); q.pop();
            if(c=='+') {
                if(everMinus) {
                    cnt++;
                    everMinus = false;
                }
                everPlus = true;
            } else {
                if(everPlus) {
                    cnt++;
                    everPlus = false;
                }
                everMinus = true;
            }
        }
        if(everMinus) cnt++;
        printf("Case #%d: %d\n", k, cnt);
    }
    return 0;
}
