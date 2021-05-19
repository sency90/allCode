#include <stdio.h>
#include <queue>
using namespace std;
int a[500001], b[500001];
priority_queue<int> mnh;
int main() {
    int n, h, ha, hb, len;
    scanf("%d %d", &n, &h);
    len = n/2;
    for(int i=0; i<len; i++) {
        scanf("%d %d", &ha, &hb);
        a[ha]++;
        b[hb]++;
    }
    for(int i=h; i>=2; i--) {
        a[i-1] += a[i];
        b[i-1] += b[i];
    }
    for(int i=1; i<=h; i++) {
        mnh.push(-(a[i]+b[h-i+1]));
    }
    int pv = mnh.top(), cnt=0;
    while(pv == mnh.top()) {
        pv = mnh.top(); mnh.pop();
        cnt++;
        if(mnh.empty()) break;
    }
    printf("%d %d", -pv, cnt);
    return 0;
}
