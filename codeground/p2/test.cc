#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;
void print() {
    for(auto &p : v) {
        printf("%d ", p);
    }
    puts("");
}
int main() {
    int n;
    scanf("%d", &n);
    v.resize(n);
    v[n-1]=12;
    print();
    v.clear();
    print();
    v.push_back(17);
    print();
    return 0;
}
