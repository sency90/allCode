#include <cstdio>
#include <iostream>
using namespace std;
int v[101];
char s[101];
char alpha[]={'a','e','i','o','u','y'};
int main() {
    int n; scanf("%d ",&n);
    for(int i=0; i<n; i++) {
        scanf("%d ", &v[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%[^\n]\n", s);
        int cnt=0;
        for(int j=0; s[j]; j++) {
            for(int k=0; k<6; k++) {
                if(s[j]==alpha[k]) {
                    cnt++;
                    break;
                }
            }
        }
        if(v[i]!=cnt) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
