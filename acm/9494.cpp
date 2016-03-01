#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int n, i, prev;
    while(true) {
        scanf("%d ", &n);
        if(n==0) return 0;
        prev = 0;
        while(n--) {
            getline(cin, s);
            for(i=prev; i<s.size(); i++) {
                if(s[i] == ' ' || s[i] == '\r' || s[i] == '\n' || s[i] == EOF) break;
            }
            prev = i;
        }
        printf("%d\n", prev+1);
    }
    return 0;
}
