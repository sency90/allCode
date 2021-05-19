#include <stdio.h>
#include <queue>
std::priority_queue<int> mnh, mnh2;
int main() {
    int d, sum=0;
    for(int i=0; i<4; i++) {
        scanf("%d", &d);
        mnh.push(-d);
    } mnh.pop();
    for(int i=0; i<2; i++) {
        scanf("%d", &d);
        mnh2.push(-d);
    } mnh2.pop();
    while(!mnh.empty()) {
        sum+=mnh.top(); mnh.pop();
    }
    sum+=mnh2.top();
    printf("%d", -sum);
    return 0;
}
