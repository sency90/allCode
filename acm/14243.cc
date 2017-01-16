#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
char p, pp;
int a=0, b=0, c=0;
string ans;
void A() {
    a--;
    ans+='A';
    pp=p; p='A';
}
void B() {
    b--;
    ans+='B';
    pp=p; p='B';
}
void C() {
    c--;
    ans+='C';
    pp=p; p='C';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='A') a++;
        else if(s[i]=='B') b++;
        else c++;
    }
    if(b && b>=2*c) B();
    else if(c) C();
    int pa=a, pb=b, pc=c;
    while(a||b||c) {
        if(p=='A') {
            if(b && b>=2*c) B();
            else if(c && pp!='C') C();
            else if(a) A();
        } else if(p=='B'){
            if(c && pp!='C') C();
            else if(a) A();
        } else {
            if(b) B();
            else if(a) A();
        }
        if(pa==a && pb==b && pc==c) return 0&puts("-1");
        else { pa=a; pb=b; pc=c; }
    }
    printf("%s", ans.c_str());
}
