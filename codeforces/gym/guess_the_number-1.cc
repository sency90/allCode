#include <iostream>
#include <string>
using namespace std;
int main() {
    string response;
    int l=1, r=1e3+1;
    for(int i=0; i<10; i++) {
        int mid = (l+r)/2;
        cout << mid << endl;
        cin >> response;
        if(response=="<") r=mid;
        else l=mid;
    }
    cout <<"! "<< l << endl;
    return 0;
}
