#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void pick(vector<int>& picked, int n, int c) {
    if(c==0) {
        for(auto &p : picked) cout << p << " ";
        puts("");
    }

    for(int i=picked.size(); i<n; i++) {
        picked.push_back(i);
        pick(picked, n, c-1);
        picked.pop_back();
    }
}
int main() {
    int n,c;
    scanf("%d%d", &n,&c);
    vector<int> v;
    pick(v,n,c);
    return 0;
}
