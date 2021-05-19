#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxheap;
    int n; scanf("%d", &n);

    if(0 == n) {
        printf("0\n");
        return 0;
    }

    while( n > 0 ) {
        maxheap.push( n % 10 );
        n /= 10;
    }
    while( !maxheap.empty() ) {
        printf("%d", maxheap.top());
        maxheap.pop();
    }
    printf("\n");
    return 0;
}
