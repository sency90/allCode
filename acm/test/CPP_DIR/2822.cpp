#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int> > v;
priority_queue<int> mnh;
bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return lhs.first > rhs.first;
}
int main() {
    int d, sum=0;
    for(int i=1; i<=8; i++) {
        scanf("%d", &d);
        v.push_back(make_pair(d, i));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<5; i++) {
        sum += v[i].first;
        mnh.push(-v[i].second);
    }
    printf("%d\n", sum);
    while(!mnh.empty()) {
        printf("%d ", -mnh.top());
        mnh.pop();
    }
    return 0;
}
