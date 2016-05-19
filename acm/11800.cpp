#include <stdio.h>
#include <algorithm>
using namespace std;
char name[][7]={"","Yakk","Doh","Seh","Ghar","Bang","Sheesh"};
char name2[][10]={"","Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh"};
int main() {
    int t, l, b;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        scanf("%d%d",&l,&b);
        if(l>b) swap(l,b);
        printf("Case %d: ", i);
        if(l==b) printf("%s\n", name2[l]);
        else {
            if(l==5 && b==6) puts("Sheesh Beesh");
            else printf("%s %s\n", name[b], name[l]);
        }
    }
    return 0;
}
