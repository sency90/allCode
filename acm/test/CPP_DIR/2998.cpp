#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
queue<int> q;
char str[101];
int spow(int a, int b) {
    int res = 1;
    for(int i=0; i<b; i++) res*=a;
    return res;
}
int main() {
    scanf("%s", str);
    int k, t, len = strlen(str);
    if(len%3 == 0) k=0;
    else k = 3-(len%3);
    for(int i=0; i<k; i++) q.push(0);

    for(int i=0; i<len; i++) q.push((int)str[i]-48);

    len += k;
    for(int i=0; i<len; i+=3) {
        t = 0;
        for(int j=2; j>=0; j--) {
            t += (q.front()*spow(2,j));
            q.pop();
        }
        printf("%d", t);
    }
    return 0;
}
