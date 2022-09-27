#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int>> v;
int main() {
    vector<int> a(3);
    vector<int> b(4);
    vector<int> c(2);
    vector<int> d(1);

    v.emplace_back(a);
    v.emplace_back(b);
    v.emplace_back(c);
    v.emplace_back(d);

    vector<int> v_sz(4);
    function< int(const vector<int>&) > sz_func = &vector<int>::size;
    std::transform(v.begin(), v.end(), v_sz.begin(), sz_func);

    int idx = 0;
    for(const auto & it : v_sz) {
        printf("v_sz[%d]: %d\n", idx++, it);
    }

    return 0;
}
