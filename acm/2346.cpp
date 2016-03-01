#include <stdio.h>
#include <deque>
using namespace std;
deque<pair<int, int> > dq;
int main() {
    pair<int, int> idx;
    int d, t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        scanf("%d", &d);
        dq.push_back(make_pair(d,i));
    }
    while(!dq.empty()) {
        idx = dq.front();
        dq.pop_front();
        if(idx.first>0) {
            for(int i=1; i<idx.first; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            idx.first = -idx.first;
            for(int i=0; i<idx.first; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        printf("%d ", idx.second);
    }
    return 0;
}
