#include <stdio.h>
#include <cstring>
using namespace std;
char s[1000];
int main() {
    scanf("%[^\n]\n", s);
    printf("%lu", strlen(s));
    return 0;
}
