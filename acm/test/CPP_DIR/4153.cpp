#include <stdio.h>
#include <algorithm>
int main() {
    int x[3];
    while(true) {
        for(int i=0; i<3; i++) scanf("%d", &x[i]);
        if(x[0]==0 && x[1]==0 && x[2]==0) return 0;
        std::sort(x, x+3);
        if(x[2]*x[2] == x[1]*x[1] + x[0]*x[0]) puts("right");
        else puts("wrong");
    }
    return 0;
}
