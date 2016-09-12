#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<cstdlib>
#include<queue>
#include<iomanip>
#include<stack>
#include<string.h>
#include<math.h>
#define MOD 1000000
#define MAX 1000000000
using namespace std;
#define FOR(i,end) for(int i = 0; i < (end) ; ++i )
string reverse1(string::iterator& it) {
    char head = *it;
    it++;
    if (head == 'b' || head == 'w') return string(1,head);

    string upperLeft = reverse1(it) ;
    string upperRight = reverse1(it) ;
    string lowerLeft = reverse1(it) ;
    string lowerRight = reverse1(it) ;

    return (string("x") + lowerLeft + lowerRight + upperLeft + upperRight );
}

int main() {
    int T ;
    cin>>T;
    while(T--) {
        string str;
        cin >> str;
        string::iterator it = str.begin();
        cout << reverse1(it) << "\n";
    }
    return 0 ;
}
