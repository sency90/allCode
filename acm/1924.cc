#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string ans[13][32];
string p[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    int idx = 0;
    for(int i=1; i<=12; i++) {
        for(int j=1; j<=31; j++) {
            if(i==2 && j>28) break;
            if((i==4 || i==6 || i==9 || i==11) && j>30) break;
            ans[i][j] = p[idx++];
            idx%=7;
        }
    }
    int m,d;
    scanf("%d%d", &m, &d);
    printf("%s\n", ans[m][d].c_str());
}
