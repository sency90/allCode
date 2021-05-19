#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main() {
    int t;
    char c;
    scanf("%d ", &t);
    for(int i=1; i<=t; i++) {
        string s;
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(c=='Z') s += "A";
            else s+=c+1;
        }
        printf("String #%d", i);
        puts("");
        cout << s;
        puts("");puts("");
    }
    return 0;
}
