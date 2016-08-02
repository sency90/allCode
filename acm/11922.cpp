#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int points[8][2]={{11,11},{4,4},{3,3},{20,2},{10,10},{14,0},{0,0},{0,0}};
char ds;
int chg(string &s) {
    if(ds == s[1]) {
        if(s[0]=='A') return points[0][0];
        else if(s[0]=='K') return points[1][0];
        else if(s[0]=='Q') return points[2][0];
        else if(s[0]=='J') return points[3][0];
        else if(s[0]=='T') return points[4][0];
        else if(s[0]=='9') return points[5][0];
        else if(s[0]=='8') return points[6][0];
        else if(s[0]=='7') return points[7][0];
    } else {
        if(s[0]=='A') return points[0][1];
        else if(s[0]=='K') return points[1][1];
        else if(s[0]=='Q') return points[2][1];
        else if(s[0]=='J') return points[3][1];
        else if(s[0]=='T') return points[4][1];
        else if(s[0]=='9') return points[5][1];
        else if(s[0]=='8') return points[6][1];
        else if(s[0]=='7') return points[7][1];
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    int n, sum=0;
    cin >> n >> ds;
    string s;
    n=4*n;
    for(int i=0; i<n; i++) {
        cin >> s;
        sum += chg(s);
    }
    cout << sum;
    return 0;
}
