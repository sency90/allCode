#include <stdio.h>
#include <map>
using namespace std;
map<char, int> mp;
char str[1000001];
char info[4][4] = {{'A','C','A','G'},{'C','G','T','A'},{'A','T','C','G'},{'G','A','G','T'}};
int main() {
    mp['A']=0;
    mp['G']=1;
    mp['C']=2;
    mp['T']=3;
    int n;
    char c;
    scanf("%d", &n);
    scanf("%s", str);
    c = str[n-1];
    for(int i=n-2; i>=0; i--) {
        c = info[mp[str[i]]][mp[c]];
    }
    printf("%c", c);
    return 0;
}
