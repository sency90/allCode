#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
char str[100001];
int main() {
    char c[2], opcode;
    scanf("%s", str);
    string s(str);
    int cs = s.size();
    int n;
    scanf(" %d", &n);
    while(n--) {
        scanf(" %c", &opcode);
        if(opcode == 'P') {
            scanf(" %s", c);
            s.insert(cs, c);
            cs++;
        } else if(opcode == 'L') {
            if(cs == 0) continue;
            else cs--;
        } else if(opcode == 'D') {
            if(cs == s.size()) continue;
            else cs++;
        } else if(opcode == 'B') {
            if(cs==0) continue;
            else {
                s.erase(cs-1, 1);
                cs--;
            }
        }
    }
    cout << s;
    return 0;
}
