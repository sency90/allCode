#include <stdio.h>
int n;
char str[101][101];
void func(char (*s)[101]) {
    for(int i=0; i<n; i++) {
        printf("%s\n", s[i]);
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s", str[i]);
    }
    func(str);
    return 0;
}
