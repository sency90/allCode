#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int x=100;
int main() {
    for(int i=0; i<10; i++) {
        v.push_back(i+1);
    }
    cout << v.size();
    puts("");
    v.clear();
    cout << v.size();
    for(int i=0; i<10; i++) {
        cout << v[i] << " ";
    }
    return 0;
}
