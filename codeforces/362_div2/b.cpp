#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string f="",m="",nf="",nm="";
    char c;
    while((c=getchar())!='.') {
        f += c;
    }
    while((c=getchar())!='e') {
        m += c;
    }
    scanf("%d", &n);

    if(n==0) {
        cout << f << "." << m;
        return 0;
    }
    int cnt=0;
    if(f == "0") {
        //m의 앞의 0의 개수를 센다
        for(int i=0; i<m.size(); i++) {
            if(m[i]=='0') cnt++;
            else break;
        }
    } else cout << f;
    if(m.size() <= n) {
        m+="00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        cout << m.substr(cnt,n-cnt);
    } else {
        cout << m.substr(cnt,n-cnt) << "." << m.substr(n);
    }
    return 0;
}
