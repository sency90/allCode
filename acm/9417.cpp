#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int d[101];
int gcd(int b, int l) {
    int t = b%l;
    if(t==0) return l;
    else return gcd(l, t);
}
char s[450];
int main() {
    int n, i, tmp, res;
    scanf("%d ", &n);
    while(n--) {
        i=0;
        res=0;
        scanf("%[^\n]\n", s);
        for(char* p=strtok(s," "); p; p=strtok(NULL," ")) {
            d[i++] = atoi(p);
        }
        for(int j=0; j<i-1; j++) {
            for(int k=j+1; k<i; k++) {
                if(d[j] > d[k]) tmp = gcd(d[j], d[k]);
                else tmp = gcd(d[k], d[j]);
                if(res < tmp) res = tmp;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
