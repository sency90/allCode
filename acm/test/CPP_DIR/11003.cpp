#include <stdio.h>
#include <deque>
using namespace std;
deque<pair<int,int> > dq;
int main() {
    int n, m, d;
    scanf("%d %d", &n, &m);
    if(m==1) {
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            printf("%d ", d);
        }
        return 0;
    } else {
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            if(dq.empty()) {
                dq.push_back(make_pair(d,i));
                printf("%d ", d);
            } else {
                if(dq.front().second < i-m+1) {
                    dq.pop_front();
                }
                while(!dq.empty() && dq.back().first > d) {
                    dq.pop_back();
                }
                dq.push_back(make_pair(d,i));
                printf("%d ", dq.front().first);
            }
        }
    }
    return 0;
}
