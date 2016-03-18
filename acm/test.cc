#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, int> m;
vector<string> v;
int main() {
    string s;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        cin >> s;
        m[s] = i;
        v[i] = s;
        printf("test\n");
    }
    for(int i=0; i<n; i++) {
        cout << m[v[i]] << '\n';
    }

    return 0;
}
