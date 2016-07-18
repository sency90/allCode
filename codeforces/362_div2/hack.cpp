#include <iostream>
using namespace std;
#define ll long long
string s;
int main() {
    cin >> s;
    int bd=0, ad=0, pt=0, i, tz=0;
    while(s[bd]!='.') bd++;
    while(s[ad+bd+1]!='e') ad++;
    i=bd+ad+2;
    while(i<s.length()) {
        pt = pt*10+(s[i]-'0'); i++;
    }
    i=bd+ad;

    while(s[i]=='0' && i>bd) tz++, i--;
    if(ad==1 && s[bd+1]=='0') {
        cout<<s.substr(0,bd);
        while(pt--) cout << "0";
    }
    else if(pt>=ad) {
        int l=pt-ad;
        cout<<s.substr(0,bd);
        cout<<s.substr(bd+1,ad);
        while(l--) cout<<"0";
    }
    else if(pt>=(ad-tz)) {
        cout << s.substr(0,bd);
        cout << s.substr(bd+1, pt);
    }
    else {
        if(bd!=1 || s[0]!='0' || pt==0)
            cout << s.substr(0,bd);
        cout<<s.substr(bd+1,pt);
        cout<<".";
        cout<<s.substr(bd+1+pt,ad-pt-tz);
    }
    cout << endl;
    return 0;
}
