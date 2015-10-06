#include <iostream>
#include <set>
using namespace std;

#define NEWINT(x) int x; cin >> x
#define GETINT(x) cin >> x
#define ASSERT(x) if(!(x)) while(true);

int main() {
    NEWINT(n);
    set<int> setn;
    int input;
    for( int i=0; i<n; i++ ) {
        cin >> input;
        setn.insert(input);
    }

    NEWINT(m);
    for (int i=0; i<m; i++) {
        cin >> input;
        if(binary_search(setn.begin(), setn.end(), input)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
