#include <stdio.h>
char a[][128] = {
    "#include<stdio.h>",
    "main()",
    "{",
    "    printf(\"Hello World\\n\");",
    "}"
};
int main() {
    for(int i=0; i<5; i++) {
        printf("%s\n", a[i]);
    }
    return 0;
}
