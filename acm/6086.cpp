#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<char,int> > v[52];
int main() {
    char s, e;
    int n, c;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%c %c %d ", s, e, c);
        if(isUpper(s)) s-='A';
        else s-='a';
        if(isUpper(e)) e-='A';
        else e-='a';
        v[s].push_back(make_pair(e,c));
        v[e].push_back(make_pair(s,c));
    }


    while(true) {
        while(!q.empty()) {
            s = q.front().first;
            c = q.front().second;
            for(int i=0; i<v[s].size(); i++) {
                e = v[s][i].first;
                if(p[e]==-1) continue;
                
            }
        }
    }
    return 0;
}
