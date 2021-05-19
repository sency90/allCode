#include <stdio.h>
#include <string.h>
#define NAN 26
int v[27][2];
void pre(int t) {
    printf("%c", t+'A');
    if(v[t][0]!=NAN) pre(v[t][0]);
    if(v[t][1]!=NAN) pre(v[t][1]);
}
void in(int t) {
    if(v[t][0]!=NAN) in(v[t][0]);
    printf("%c", t+'A');
    if(v[t][1]!=NAN) in(v[t][1]);
}
void post(int t) {
    if(v[t][0]!=NAN) post(v[t][0]);
    if(v[t][1]!=NAN) post(v[t][1]);
    printf("%c", t+'A');
}
int main() {
    for(int i=0; i<26; i++) {
        v[i][0] = NAN;
        v[i][1] = NAN;
    }
    int n; scanf("%d", &n);
    char c[3];
    while(n--) {
        for(int i=0; i<3; i++) {
            scanf(" %c", &c[i]);
            if(c[i]=='.') c[i] = NAN;
            else c[i] = c[i]-'A';
        }
        v[c[0]][0] = c[1];
        v[c[0]][1] = c[2];
    }
    pre(0); printf("\n");
    in(0); printf("\n");
    post(0); printf("\n");
    return 0;
}
