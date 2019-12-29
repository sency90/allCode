#include <cstdio>
#include <deque>
using namespace std;
deque<int> dq;
int player[2];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        dq.push_back(x);
    }

    int t=0;
    while(!dq.empty()) {
        if(dq.front() > dq.back()) player[t]+=dq.front(), dq.pop_front();
        else player[t]+=dq.back(), dq.pop_back();

        t^=1;
    }
    printf("%d %d\n", player[0],player[1]);
    return 0;
}
