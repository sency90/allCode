#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, d;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> d;
        v.push_back(d);
    }
    vector<int> tmp = v;
    vector<int> tmp2 = v;
    sort(tmp2.begin(), tmp2.end());
    sort(tmp.begin(), tmp.end());
    if(tmp == tmp2) puts("the same");
    else puts("diff");
    return 0;
}
