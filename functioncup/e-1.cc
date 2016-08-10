#include <cstdio>
using namespace std;
int main() {
    int n,pd,d;
    scanf("%d", &n);
    scanf("%d", &pd);
    int first = pd;
    for(int i=0; i<n-1; i++) {
        scanf("%d", &d);
        if(pd-(d%pd)<=first || d%pd==0) {
            pd=d;
            continue;
        }
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}
