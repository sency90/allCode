#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;
char str[]={'A','I','O','U','E'};
string mkRnd() {
    int len = 2;
    string s="";
    for(int i=0; i<len; i++) {
        int x = rand()%5;
        s+=str[x];
    }
    return s;
}

int main() {
    srand(time(0));
    freopen("in.txt","w",stdout);
    int n=16; printf("%d\n", n);
    for(int i=0; i<n; i++) printf("%s\n", mkRnd().c_str());
    return 0;
}
