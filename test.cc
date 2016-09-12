#include <string>
#include <iostream>
#include <cstring>
using namespace std;
string rev(string::iterator& it) {
    char head = *it ;
    it++ ;
    if ( head == 'b' || head == 'w' )
        return string(1,head);

    string upperLeft = rev(it) ;
    string upperRight = rev(it) ;
    string lowerLeft = rev(it) ;
    string lowerRight = rev(it) ;

    return (string("x") + lowerLeft + lowerRight + upperLeft + upperRight );
}
int main() {
    string H;
    cin >> H;
    string ans;
    //string ans = rev(H.begin());
    string::iterator it = H.begin();
    ans = rev(it);
    cout << ans << "\n";
    return 0;
}
