#include <stdio.h>
#include <cstring>
using namespace std;
char input[6], c[2];
int dir=1, cnt[26];
int main() {
    int n,x,px=0,curIdx=25,tmp;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s%d", input, &x);
        tmp = (x-px)/26;
        for(int i=0; i<26; i++) cnt[i]+=tmp;
        tmp = (x-px)%26;
        for(int i=0; i<tmp; i++) {
            curIdx+=dir;
            if(curIdx<0) curIdx+=26;
            else if(curIdx>=26) curIdx-=26;
            cnt[curIdx]++;
        }
        px = x;
        if(input[0]=='S') dir *= -1;
        else {
            scanf("%s", c);
            printf("%d\n", cnt[c[0]-'a']);
        }
    }
    return 0;
}
