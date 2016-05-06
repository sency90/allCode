#include <stdio.h>
#include <deque>
using namespace std;
deque<char> dq;
char bra[500001], op[500001];
int main() {
    int n, m, p;
    scanf("%d%d%d",&n,&m,&p);
    scanf("%s", bra);
    for(int i=0; i<m; i++) {
        dq.push_back(bra[i]);
    }
    if(p<=n-p) {
        for(int i=1; i<p; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    } else {
        for(int i=0; i<n-p+1; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }
    scanf("%s", op);
    for(int i=1; i<m; i++) {
        if(op[i]=='R') {
            dq.push_back(dq.front());
            dq.pop_front();
        } else if(op[i]=='L') {
            dq.push_front(dq.back());
            dq.pop_back();
        } else {
            if(dq.front() == '(') {
                s.push('(');
                dq.pop_front();
                while(!s.empty()) {
                    if(dq.front()=='(') {
                        dq
                    }
                    if(s.push(dq.front()))
                }
            } else {

            }
        }

    }
    return 0;
}
