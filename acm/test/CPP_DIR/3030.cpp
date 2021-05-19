#include <stdio.h>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
string federer = "federer";
int main() {
    char a[21], b[21], c;
    int n, scr[2][3], w[2];
    bool turnA = true;
    scanf("%s %s",a,b);
    scanf("%d ", &n);
    if(a==federer) printf("a is federer!!\n");
    else if(b==federer) printf("b is federer!!\n");
    while(n--) {
        while(true) {
            int idx = 0;
            while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
                if(c==' ') {
                    idx++;
                    continue;
                }
                if(turnA) {
                    scr[0][idx] = c-'0';
                    turnA = false;
                } else {
                    if(c==':') continue;
                    turnA = true;
                    scr[1][idx] = c-'0';
                }
            }
            if(c==EOF) break;
            else if(idx<1 || idx>4) {
                puts("ne");
                continue;
            }
            bool good = true;
            memset(w, 0, sizeof(w));

            for(int i=0; i<=idx; i++) {
                int sum = scr[0][i]+scr[1][i];
                if(sum <= 10 || sum==14) {
                    if((scr[0][i]!=6 && scr[1][i]!=6) || abs(scr[0][i]-scr[1][i])<2) {
                        good = false;
                        break;
                    }

                    if(scr[0][i] > scr[1][i]) w[0]++;
                    else if(scr[0][i] < scr[1][i]) w[1]++;
                    else {
                        good = false;
                        break;
                    }
                } else if(sum == 12 || sum == 13) {
                    if((scr[0][i]!=7 && scr[1][i]!=7) || scr[0][i] == scr[1][i]) {
                        good = false;
                        break;
                    }

                    if(scr[0][i] > scr[1][i]) w[0]++;
                    else if(scr[0][i] < scr[1][i]) w[1]++;
                    else {
                        good = false;
                        break;
                    }
                } else {
                    good = false;
                    break;
                }

                if(w[0]==2 || w[1]==2) {
                    if(idx!=i) {
                        good = false;
                        break;
                    }
                }
            }

            if(good) {
                if(w[0]==w[1]) puts("ne");
                else if(w[0]>w[1]) {
                    if(b == federer) puts("ne");
                    else puts("da");
                } else {
                    if(a == federer) puts("ne");
                    else puts("da");
                }
            } else {
                puts("ne");
            }
        }
    }
    return 0;
}
