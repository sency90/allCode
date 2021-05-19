#include <stdio.h>
#include <string>
using namespace std;
int main() {
    char buf[11];
    int n, cnt=0;
    scanf("%s %d", buf, &n);
    string needle(buf), hay;
    for(int i=0; i<n; i++) {
        scanf("%s", buf); hay = buf;
        hay.append(hay);
        if(hay.find(needle) != string::npos) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
