#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    char s[101];
    scanf("%s", s);
    for(char *p=strtok(s, "-"); p; p=strtok(0, "-")) {
        printf("%c", p[0]);
    }
}
