#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
char s[101];
vector<vector<string>> v;
int main() {
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        v.clear();
        v.resize(101, vector<string>());
        for(int i=0; i<10; i++) {
            int d;
            scanf("%s %d",s,&d);
            v[d].push_back(string(s));
        }
        printf("Case #%d:\n",z);
        for(int i=100; i>=1; i--) {
            if(v[i].empty()) continue;
            for(auto &p: v[i]) {
                printf("%s\n",p.c_str());
            } break;
        }
    }
    return 0;
}
