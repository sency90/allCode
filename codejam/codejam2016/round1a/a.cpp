#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
char str[101], mxc;
int main() {
    int t, len;
    scanf("%d ", &t);
    for(int k=1; k<=t; k++) {
        printf("Case #%d: ", k);
        string s="";
        mxc='A';
        scanf("%s", str);
        len = strlen(str);
        for(int i=0; i<len; i++) {
            if(str[i]=='\0') break;
            if(mxc <= str[i]) {
                mxc = str[i];
                s = str[i] + s;
            } else {
                s = s + str[i];
            }
        }
        cout << s << '\n';
    }
    return 0;
}
