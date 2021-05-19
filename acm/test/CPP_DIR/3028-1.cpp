#include <stdio.h>
#include <algorithm>
#include <cctype>
using namespace std;
int main() {
    char c;
    int cup[3] = {1,0,0};
    while(isupper(c=getchar())) {
        if(c=='A') swap(cup[0], cup[1]);
        else if(c=='B') swap(cup[1], cup[2]);
        else if(c=='C') swap(cup[0], cup[2]);
    }
    for(int i=0; i<3; i++) {
        if(cup[i]) printf("%d", i+1);
    }
    return 0;
}
