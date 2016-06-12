#include <stdio.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
char puz[4][5];
int main() {
    int sum = 0, t;
    for(int i=0; i<4; i++) {
        scanf("%s", puz[i]);
        for(int j=0; j<4; j++) {
            if(puz[i][j]=='.') continue;
            t=puz[i][j]-'A';
            sum+=abs((t/4)-i)+abs((t%4)-j);
        }
    }
    printf("%d", sum);
    return 0;
}
