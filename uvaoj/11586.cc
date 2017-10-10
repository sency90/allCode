#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cassert>
using namespace std;
char s[200];
vector<int> v;
vector<vector<int>> g;
int b[51],chk[51];
int CC=1;
bool bipartite(int x) {
    if(chk[x]==CC) return false;
    chk[x]=CC;
    for(int y: g[x]) {
        if(b[y]<0 || bipartite(b[y])) {
            b[y]=x;
            return true;
        }
    }
    return false;
}
int main() {
    int tc; scanf("%d ", &tc);
    while(tc--) {
        gets(s);
        v.clear();
        for(char *p=strtok(s," ");p;p=strtok(0," ")) {
            if(p[0]=='M'){
                if(p[1]=='M') v.push_back(0);
                else v.push_back(1);
            } else {
                if(p[1]=='M') v.push_back(2);
                else v.push_back(3);
            }
        }
        g.clear();
        g.resize(v.size(), vector<int>());
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<v.size(); j++) {
                if(i==j) continue;
                if(v[i]<=1) {
                    if(v[j]&1) g[i].push_back(j);
                    else continue;
                } else {
                    if(!(v[j]&1)) g[i].push_back(j);
                    else continue;
                }
            }
        }

        memset(b,-1,sizeof(b));
        int cnt=0;
        for(int i=0; i<v.size(); i++) {
            if(bipartite(i)) cnt++;
            CC++;
        }
        if(cnt == v.size()) puts("LOOP");
        else puts("NO LOOP");
    }
    return 0;
}

