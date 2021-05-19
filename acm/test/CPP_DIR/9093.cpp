#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main() {
    int n, i;
    char c, word[21];
    scanf("%d ", &n);
    while(n--) {
        memset(word, 0, sizeof(word));
        i=0;
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(c==' ') {
                reverse(word, word+i);
                i=0;
                printf("%s ", word);
                memset(word, 0, sizeof(word));
            } else {
                word[i++] = c;
            }
        }
        if(strlen(word) != 0) {
            reverse(word, word+i);
            i=0;
            printf("%s", word);
        }
        printf("\n");
    }
    return 0;
}
