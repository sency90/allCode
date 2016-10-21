#include <cstdio>
using namespace std;
int main() {
    int n=7;
    for(int i=7; i!=0; i&=(i-1)) {
        printf("%d\n", i);
    }

    return 0;
}
