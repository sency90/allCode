#include <stdio.h>
#include <algorithm>
using namespace std;
char a[3]={1,0,0};
int main() {
    char c;
    while(scanf("%1c", &c)!=EOF) {
        if(c=='A') swap(a[0], a[1]);
        else if(c=='B') swap(a[1], a[2]);
        else if(c=='C') swap(a[0], a[2]);
    }
    for(int i=0; i<3; i++) {
        if(a[i]) printf("%d", i+1);
    }
    return 0;
}
