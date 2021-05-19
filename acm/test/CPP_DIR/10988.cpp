#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    char t[101];
    scanf("%s", t);
    int len = strlen(t);
    string str(t);
    reverse(t, t+len);
    string rstr(t);

    if(str.find(rstr) != string::npos) printf("1");
    else printf("0");
    return 0;
}
