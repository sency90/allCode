#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char H[1000001], N[1000001];
int h, n;
vector<int> kmp() {
    vector<int> pi(n,0);
    int begin=1, marked=0;
    while(begin+marked <= n) {
        if(N[marked] == N[begin+marked]) {
            marked++;
            pi[begin+marked-1]=marked;
        } else {
            if(marked == 0) begin++;
            else {
                begin += marked-pi[marked-1];
                marked = pi[marked-1];
            }
        }
    }

    vector<int> ret;
    begin=0; marked=0;
    while(begin+n <= h) {
        if(marked<n && H[begin+marked] == N[marked]) {
            if(++marked == n) ret.push_back(begin+1);
        } else {
            if(marked == 0) begin++;
            else {
                begin += marked-pi[marked-1];
                marked = pi[marked-1];
            }
        }
    }
    return ret;
}
int main() {
    scanf("%[^\n]\n", H);
    scanf("%[^\n]\n", N);
    h=strlen(H), n=strlen(N);
    vector<int> ans = kmp();
    printf("%lu\n", ans.size());
    for(int i=0; i<ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
