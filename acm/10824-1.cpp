#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;
int main() {
    string s1, s2;
    char a[8], b[8], c[8], d[8];
    scanf("%s %s %s %s", a, b, c, d);
    s1 = a;
    s1 += b;
    s2 = c;
    s2 += d;
    int d1 = stoi(s1);
    int d2 = stoi(s2);
    printf("%d", d1+d2);
}
