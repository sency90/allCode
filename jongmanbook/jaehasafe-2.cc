#include <stdio.h>
char s[20002], ns[20002];
int strlen(char *s) {
    int i=0; for(;s[i];i++);
    return i;
}
void doubleString(char *s, int len) {
    for(int i=0; i<len; i++) s[i+len]=s[i];
    s[len*2]=0;
}
int pi[1001];
void init(int *pi, int len) {
    for(int i=0; i<len; i++) pi[i]=0;
}
int kmp(char *H, char *N, int len) {
    int h=len*2, n=len;
    H[h]=0; N[n]=0;
    init(pi,len);
    for(int i=1,m=0; i<n; i++) {
        while(m!=0 && N[i]!=N[m]) m=pi[m-1];
        if(N[i]==N[m]) pi[i]=++m;
    }
    for(int i=0,m=0; i<h; i++) {
        while(m!=0 && H[i]!=N[m]) m=pi[m-1];
        if(H[i]==N[m]) if(++m == n) return i-m+1;
    }
    return 0;
}
void assign(char *s, char *ns, int len) {
    for(int i=0; i<len; i++) s[i]=ns[i];
    s[len]=0;
}

int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,ans=0;
        scanf("%d%s", &n,s);
        int len = strlen(s);
        for(int i=0; i<n; i++) {
            scanf("%s",ns);
            if(i&1) {
                doubleString(s,len);
                ans+=kmp(s,ns,len);
            } else {
                doubleString(ns,len);
                ans+=kmp(ns,s,len);
            }
            assign(s,ns,len);
        }
        printf("%d\n",ans);
    }
    return 0;
}
