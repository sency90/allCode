#include <iostream>
using namespace std;
int n;
bool chk[101];
void f(int x) {
    if(x==0) {
        bool first = true;
        printf("{ ");
        for(int i=1; i<=n; i++) {
            if(chk[i]) {
                if(first) printf("%d",i), first^=1;
                else printf(",%d",i);
            }
        } printf(" }\n");
        return;
    }

    chk[x]=true;
    f(x-1);
    chk[x]=false;
    f(x-1);
}
int main() {
    scanf("%d", &n);
    f(n);
    return 0;
}
