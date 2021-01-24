#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char N[20], nN[20];
int d[2],c[2],cnt[2];
bool judge(char *s) {
    memset(cnt, 0, sizeof(cnt));
    int len = strlen(s);
    for(int i=0; i<len; i++) {
        for(int j=0; j<2; j++) {
            if(s[i]-'0' == d[j]) cnt[j]++;
        }
    }

    for(int j=0; j<2; j++) {
        if(cnt[j]<c[j]) return false;
    }
    return true;
}
int main() {
    scanf("%s %d %d %d %d",N,&d[0],&c[0],&d[1],&c[1]);
    int len = strlen(N);

    //make d[0]>d[1]
    if(d[0]<d[1]) {
        swap(d[0],d[1]);
        swap(c[0],c[1]);
    }

    if(hasAns) printf("%s\n", N);

    strcpy(nN, N);
    while(1) {
        if(judge(nN)) return 0&printf("%s\n", nN);

        if(c[0]+c[1]>len) {
            for(int i=0; i<cnt[0])
        }
    }



    return 0;
}
