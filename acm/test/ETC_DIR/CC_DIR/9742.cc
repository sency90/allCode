#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[11];
int n, fact[11]={1,1,};
int main() {
    for(int i=2; i<=10; i++) fact[i]=fact[i-1]*i;
    while(~scanf("%s %d",s,&n)) {
        printf("%s %d = ",s,n);
        int len = strlen(s);
        if(n>fact[len]) printf("No permutation\n");
        else {
            sort(s,s+len);
            for(int i=1; i<n; i++) next_permutation(s,s+len);
            printf("%s\n", s);
        }
    }
    return 0;
}
