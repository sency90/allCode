#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for(int i=0; i<5; i++) {
        v.push_back(i*3);
    }
    printf("%d", v.back());
    return 0;
}
