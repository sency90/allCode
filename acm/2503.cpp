#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
char a[27][4] = {0,};
int main() {
    string str[729], s, ss, sss;
    int z = 0;
    for(int i=0; i<27; i++) {
        for(int j=0; j<3; j++) {
            sprintf(a[i], "%s", "123");
            //a[i][j]
        }
    }
    for(int i=1; i<=9; i++) {
        for(int j=1; i<=9; j++) {
            for(int k=1; k<=9; k++) {
                sprintf(s, "%d", i);
                sprintf(ss, "%d", j);
                sprintf(sss, "%d", k);
                str[z++] += (s+ss+sss);
            }
        }
    }

    for(int i=0; i<729; i++) cout << str[i] << '\n';
    return 0;
}
