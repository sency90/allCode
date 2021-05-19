#include <stdio.h>
int main() {
    int i=0, k=0, n;
    scanf("%d", &n); getchar();
    char c, a[1001], b[1001];
    bool ret = true, x = !(n%2);
    while((c=getchar())!='\n' && c!=' ' && c!='\r') a[i++] = c-48;
    i=0;
    while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
        if(!ret) continue;
        else if( ((!a[i]&(c-48))|(!(c-48)&a[i])) == x ) ret = false;
        i++;
    }
    if(ret) printf("Deletion succeeded");
    else printf("Deletion failed");
    return 0;
}
