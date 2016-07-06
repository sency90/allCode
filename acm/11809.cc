#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string a, b, x, y;
int main() {
    cin >> a >> b;
    while(a.size() < b.size()) a="0"+a;
    while(b.size() < a.size()) b="0"+b;
    for(int i=0; i<a.size(); i++) {
        if(a[i]>b[i]) x+=a[i];
        else if(a[i]<b[i]) y+=b[i];
        else {
            x+=a[i];
            y+=b[i];
        }
    }

    if(x.size()==0) puts("YODA");
    else cout << stoi(x) << "\n";
    if(y.size()==0) puts("YODA");
    else cout << stoi(y) << "\n";
    return 0;
}
