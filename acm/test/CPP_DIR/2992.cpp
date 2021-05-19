#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
char str[7], ori[7];
int main() {
    scanf("%s", str);
    strcpy(ori, str);
    int len = strlen(str);
    do {
        if(strcmp(ori, str)) {
            printf("%s", str);
            return 0;
        }
    } while(next_permutation(str, str+len));
    puts("0");
}
