#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    char c;
    int cnt=0,n;
    scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        scanf("%c", &c);
        if(c=='B') cnt++;
        else {
            if(cnt) v.push_back(cnt);
            cnt=0;
        }
    }
    if(cnt!=0) v.push_back(cnt);
    printf("%lu\n", v.size());
    for(int i=0; i<v.size(); i++) {
        printf("%d ", v[i]);
    }
    return 0;
}
