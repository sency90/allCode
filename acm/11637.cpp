#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<pair<int, int> > maxheap;
int main() {
    int t, sum, n, d;
    scanf("%d", &t);
    while(t--) {
        sum = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            maxheap.push(make_pair(d, i));
            sum += d;
        }
        pair<int, int> t = maxheap.top(); maxheap.pop();
        if(t.first == maxheap.top().first) printf("no winner\n");
        else {
            if(t.first*2 > sum) printf("majority winner ");
            else printf("minority winner ");
            printf("%d\n", t.second+1);
        }
        while(!maxheap.empty()) maxheap.pop();
    }
    return 0;
}
