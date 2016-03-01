#include <stdio.h>
#include <queue>
using namespace std;
queue<char> q;
int main() {
    char c;
    int t, cnt;
    scanf("%d", &t); getchar();
    while(t--) {
        cnt = 0;
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            q.push(c);
            if(c==' ') {
                cnt++;
                if(cnt == 2) {
                    cnt=0;
                    break;
                }
            }
        }
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            printf("%c", c);
        }
        printf(" ");
        while(!q.empty()) {
            printf("%c", q.front()); q.pop();
        }
        printf("\n");
    }
    return 0;
}
