#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mnh;
int main() {
    int n; scanf("%d", &n);
    int d;
    while(n--) {
        scanf("%d", &d);
        mnh.push(-d);
    }
    while(!mnh.empty()) {
        printf("%d\n", -mnh.top());
        mnh.pop();
    }
    return 0;
}
