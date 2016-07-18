#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
string s;
int main() {
    int n, k, x;
    scanf("%d%d",&n,&k);
    int b = n/2;
    int a = n-b;
    if(k>a*b) {
        puts("-1");
        return 0;
    }
    x=b;
    for(int i=0; i<b; i++) {
        s+='B';
    }
    for(int i=0; i<a; i++) {
        int cnt=0;
        for(;x>=k;x--) cnt++;
        if(cnt) x++;
        s=s.substr(0,b-x)+'A'+s.substr(b-x);
        k-=x;
        b++;
    }
    cout << s;
    return 0;
}
