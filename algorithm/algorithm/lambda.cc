#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> sfx;
int main() {
    string s="mississipi";
    sfx.resize(s.size());

    for (int i=0; i<s.size(); i++) sfx[i] = i;

    std::sort(sfx.begin(), sfx.end(), [&](int lhs, int rhs){ return s[sfx[lhs]] < s[sfx[rhs]]; });

    for (int i=0; i<s.size(); i++) printf("%d %s\n", sfx[i], s.c_str()+sfx[i]);

    printf("\n");
    return 0;
}
