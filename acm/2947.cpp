#include <stdio.h>
#include <algorithm>
using namespace std;
int v[5];
int main() {
    for(int i=0; i<5; i++) {
        scanf("%d", v+i);
    }
    bool isAns=false;
    while(!isAns) {
        for(int i=1; i<5 && !isAns; i++) {
            if(v[i-1]>v[i]) {
                swap(v[i-1], v[i]);
                isAns = true;
                for(int i=0; i<5; i++) {
                    printf("%d ", v[i]);
                    if(i+1!=v[i]) isAns = false;
                }
                puts("");
            }
        }
    }
    return 0;
}
