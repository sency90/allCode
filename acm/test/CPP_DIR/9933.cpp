#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[100][15], temp[15];
int len[100];
int main() {
    int n, i, j;
    scanf("%d ", &n);
    for(int k=0; k<n; k++) {
        scanf("%s", str[k]);
        len[k] = strlen(str[k]);
    }
    if(n==1) printf("%d %s\n", len[0], str[0]);
    for(i=0; i<n-1; i++) {
        strcpy(temp, str[i]);
        reverse(str[i], str[i]+len[i]);
        if(!strcmp(str[i], temp)) printf("%d %c\n", len[i], str[i][len[i]/2]);
        for(j=i+1; j<n; j++) {
            if(len[i] != len[j]) continue;
            if(!strcmp(str[i], str[j])) break;
        }
        if(j!=n) {
            printf("%d %c\n", len[j], str[j][len[j]/2]);
            return 0;
        }
    }
    return 0;
}
