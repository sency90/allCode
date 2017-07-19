#include <iostream>
using namespace std;
int main() {
    int t=1;
    char c;
    while((c=getchar())!=EOF) {
        if(c=='"') {
            if(t) printf("``");
            else printf("''");
            t^=1;
        } else putchar(c);
    }
    return 0;
}
