#include <stdio.h>
 
int saveCh[26] = {0,};
char ans, c;
int i;
 
int max, maxi = 0;
bool canBeQ = false;
 
int main() {
    while( (c = getchar()) != '\n' &&  c != '\r' && c != ' ' && c != EOF) {
        if(c <= 'Z') ++saveCh[c-'A'];
        else ++saveCh[c-'a'];
    }
 
    max = saveCh[0];
    for(i=1; i<26; i++) {
        if(max < saveCh[i]) {
            max = saveCh[i];
            maxi = i;
            canBeQ = false;
        } else if(max == saveCh[i]) {
            canBeQ = true;
        }
    }
 
    if(canBeQ) printf("?\n");
    else printf("%c\n", maxi+'A');
    return 0;
}