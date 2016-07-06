#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size()) swap(a,b);
    for(int i=0; i<6; i++) {
        b += b;
        a += a;
    }
    int i;
    for(i=0; i<a.size(); i++) {
        if(b[i]!=a[i]) break;
    }
    if(i==a.size()) cout << "1";
    else cout << "0";
    return 0;

}
