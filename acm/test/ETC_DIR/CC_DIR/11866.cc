#include <cstdio>
#include <deque>
using namespace std;
deque<int> dq;
int main() {
    int n,k; scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) dq.push_back(i);
    bool isfirst = true;
    printf("<");
    while(!dq.empty()) {
        for(int i=0; i<k; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        if(!dq.empty()) {
            if(isfirst) printf("%d", dq.back());
            else printf(", %d", dq.back());
            dq.pop_back();
            isfirst = false;
        }
    }
    puts(">");
    return 0;
}
