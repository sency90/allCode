#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char l[500][31], s[2500][51];
int chg(char c) {
    if(c=='A') return 0;
    else if(c=='C') return 1;
    else if(c=='G') return 2;
    else return 3;
}
int table[50][4];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) {
        scanf("%s", l[i]);
    }
    for(int i=0; i<m; i++) {
        scanf("%s", s[i]);
        for(int j=0; s[i][j]; j++) {
            table[j][chg(s[i][j])]++;
        }
    }

    const int inf = 0x3f3f3f3f;
    int len = strlen(l[0]);
    int ans=0;
    //vector<int> v;
    for(int i=0; i<n; i++) {
        for(int j=0; j+len<m; j++) {
            int mn = inf;
            //v.clear();
            for(int r=0; r<len; r++) {
                //v.push_back(table[j+r][chg(s[i][r])]);
                mn=min(mn,table[j+r][chg(s[i][r])]);
            }
            //sort(v.begin(), v.end());
            //int mn = v[k];
            //printf("mn: %d\n", v[k]);
            if(mn==inf) mn=0;
            if(mn!=0) {
                for(int r=0; r<len; r++) {
                    table[j+r][chg(s[i][r])]-=mn;
                    if(table[j+r][chg(s[i][r])]<0) table[j+r][chg(s[i][r])]=0;
                }
            }
            ans+=mn;
        }
    }
    printf("%d\n", ans);
    return 0;
}
