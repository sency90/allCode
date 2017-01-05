#include <vector>
#include <iostream>
using namespace std;
vector<int> v(4,0);
void print(vector<int>& v, int at, int by) {
    v[at]+=by;
    for(int i=0; i<4; i++) cout << v[i];
    cout << endl;
}
int main() {
    int b,c,pb,pc,at=0,by=1;
    cout << "0000" << endl;
    cin >> b >> c;
    if(b==4) return 0;

    pb=b; pc=c;
    while(b!=4) {
        print(v,at,by);
        cin>>b>>c;
        if(by==0) {
            by++;
            pb=b; pc=c;
            continue;
        }

        if(pb==b) by=1;
        else if(pb<b) {
            at++;
            by=0;
        } else {
            v[at]-=1;
            at++;
            by=0;
        }
        pb=b; pc=c;
    }
    return 0;
}
