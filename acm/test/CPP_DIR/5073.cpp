#include <stdio.h>
#include <algorithm>
using namespace std;
int x[3], cnt, ans;
int main() {
    while(true) {
        cnt=0;
        for(int i=0; i<3; i++) {
            scanf("%d", x+i);
            if(x[i]==0) cnt++;
        }
        if(cnt==3) return 0;
        sort(x, x+3);
        if(x[0]==x[1]) {
            if(x[1]==x[2]) ans=0;
            else ans=1;
        } else if(x[1]==x[2]) ans=1;
        else {
            if(x[0]+x[1] <= x[2]) ans=3;
            else ans=2;
        }

        switch(ans) {
            case 0: puts("Equilateral"); break;
            case 1: puts("Isosceles"); break;
            case 2: puts("Scalene"); break;
            case 3: puts("Invalid"); break;
        }
    }
    return 0;
}
