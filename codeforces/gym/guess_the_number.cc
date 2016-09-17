#include <iostream>
#include <string>
using namespace std;
int main() {
    //ios::sync_with_stdio(false);
    //in.tie(0); cout.tie(0);
    string response;
    int l=1, r=1e6+1;
    for(int i=0; i<20; i++) {
        int mid = (l+r)/2;
        cout << mid << endl;
        cin >> response;
        if(response=="<") r=mid;
        else l=mid;
    }
    cout <<"! "<< l << endl;
    return 0;
}
