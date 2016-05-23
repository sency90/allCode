#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
map<char, int> m;
char s[4];
int main() {
    int a[3];
    for(int i=0; i<3; i++) {
        scanf("%d",a+i);
    }
    scanf("%s",s);
    sort(a, a+3);
    m['A']=a[0];
    m['B']=a[1];
    m['C']=a[2];
    for(int i=0; i<3; i++) {
        printf("%d ",m[s[i]]);
    }
}
