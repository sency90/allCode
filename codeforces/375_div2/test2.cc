#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int a[3];
    int sum, key;
    while(cin>>a[0]>>a[1]>>a[2]) {
        key=0;
        sort(a,a+3);
        cout<<(a[2]-a[0])<<endl;
    }
    return 0;
}
