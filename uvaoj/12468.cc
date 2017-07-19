#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    while(true) {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<0 && y<0) return 0;
        printf("%d\n",min({x+100-y,y+100-x,abs(x-y)}));
    }
    return 0;
}
