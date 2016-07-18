#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void pick(int n, vector<int>& v, int c) {
    if(c==0) {
        for(auto &p : v) cout << p << " ";
        puts("");
        return;
    }
    int smallest = v.empty()? 0:v.back()+1;

    for(int i=smallest; i<n; i++) {
        v.push_back(i);
        pick(n, v, c-1);
        v.pop_back();
    }
}
int main() {
    int n; scanf("%d", &n);
    vector<int> v;
    pick(n,v,4);
    return 0;
}
