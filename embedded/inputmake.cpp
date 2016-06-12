#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string str;
char s[30];
int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(scanf("%s", s)!=EOF) {
        for(char *p=strtok(s," ");p;p=strtok(0," ")) {
            str+=*p;
            str+=",";
        }
    }
    cout << str;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
