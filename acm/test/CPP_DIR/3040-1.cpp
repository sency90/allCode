#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mnh;
int v[9];
int sum=0;
int main() {
    for(int i=0; i<9; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sum-=100;
    bool good = false;
    int i, j;
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            if(sum==v[i]+v[j]) {
                good = true;
                break;
            }
        }
        if(good) break;
    }
    for(int k=0; k<9; k++) {
        if(k!=i && k!=j) mnh.push(-v[k]);
    }
    while(!mnh.empty()) {
        printf("%d\n", -mnh.top());
        mnh.pop();
    }
    return 0;
}
