#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> > mnh;
int main() {
    int t, d; scanf("%d", &t);
    while(t--) {
        scanf("%d", &d);
        if(d==0) {
            if(mnh.empty()) {
                puts("0");
                continue;
            }
            printf("%d\n", mnh.top());
            mnh.pop();
        } else mnh.push(d);
    }
    return 0;
}
