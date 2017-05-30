#include "Vector.h"
#include <algorithm>
using namespace std;
int main() {
    Vector<int> v;
    for(int i=0; i<10; i++) v.push_back(10-i);
    for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
    puts("");
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
    puts("");
    printf("%d", *(v.begin()+9));
    return 0;
}
