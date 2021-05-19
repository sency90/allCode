#include <stdio.h>
#include <deque>
using namespace std;
int main() {
    deque<int> dq;
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        dq.push_back(i);
    }
    int tmp=0;
    while(!dq.empty()) {
        tmp = dq.front();
        dq.pop_front();
        if(dq.empty()) break;
        dq.push_back(dq.front());
        dq.pop_front();
    }
    printf("%d", tmp);
    return 0;
}
