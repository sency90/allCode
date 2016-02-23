#include <stdio.h>
int main() {
    int d;
    bool asc = true, dsc = true;
    for(int i=1,j=8; i<=8; i++, j--) {
        scanf("%d", &d);
        if(d!=i) asc = false;
        if(d!=j) dsc = false;
    }
    if(!asc && !dsc) printf("mixed");
    else if(!asc) printf("descending");
    else printf("ascending");
    return 0;
}
