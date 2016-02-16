#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
struct S{
    char name[11], lang, eng, math;
};
bool nameCmp(S x, S y) {
    if(strcmp(x.name, y.name) < 0 ) return true;
    else return false;
}
bool langCmp(S x, S y) {
    return x.lang > y.lang;
}
bool engCmp(S x, S y) {
    return x.eng < y.eng;
}
bool mathCmp(S x, S y) {
    return x.math > y.math;
}
vector<S> v;
int main() {
    S s;
    //char n[11], l, e, m;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s %hhd %hhd %hhd", s.name, &s.lang, &s.eng, &s.math);
        v.push_back(s);
    }
    sort(v.begin(), v.end(), nameCmp);
    sort(v.begin(), v.end(), mathCmp);
    sort(v.begin(), v.end(), engCmp);
    sort(v.begin(), v.end(), langCmp);
    for(int i=0; i<n; i++) {
        printf("%s\n", v[i].name);
    }
    return 0;
}
