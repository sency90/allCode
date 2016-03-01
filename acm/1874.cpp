#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
stack<int> s;
vector<char> v;
int seq[100001];
int main() {
    int n, max=0;
    scanf("%d", &n);
    seq[0] = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &seq[i]);
    }
    for(int i=0; i<n; i++) {
        if(seq[i] < seq[i+1]) {
            for(int j=max+1; j<=seq[i+1]; j++) {
                s.push(j);
                v.push_back('+');
            }
            if(max < s.top()) max = s.top();
            s.pop();
            v.push_back('-');
        } else {
            if(s.empty()) {
                puts("NO");
                return 0;
            }
            if(s.top() == seq[i+1]) {
                s.pop();
                v.push_back('-');
            } else {
                puts("NO");
                return 0;
            }
        }
    }
    for(auto x : v) printf("%c\n", x);
    return 0;
}
