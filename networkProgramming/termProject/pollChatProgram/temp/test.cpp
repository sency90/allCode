#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define X "-1"

int main() {
    
    printf("%s: sizeof:%d, strlen:%d, atoi:%d\n", X, sizeof(X), strlen(X), atoi(X));
    return 0;
}