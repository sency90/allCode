#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int chg(char x) {
    return x-'0';
}
bool judge(int x, int y) {
    return x/10==y%10 && x%10==y/10;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int x[2];
    x[0]=chg(s[0])*10+chg(s[1]);
    x[1]=chg(s[3])*10+chg(s[4]);
    int cnt=0;
    while(true) {
        if(judge(x[0],x[1])) break;
        else {
            cnt++;
            x[1]++;
            if(x[1]>=60) {
                x[1]=0;
                x[0]++;
                if(x[0]>=24) {
                    x[0]=0;
                }
            }

        }
    }
    printf("%d", cnt);
    return 0;
}
