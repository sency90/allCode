#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
struct Name{
    char name[11];
};
struct Lang{
    char lang;
};
struct Eng{
    char eng;
};
struct Math{
    char math;
};
struct All{
    Name _name;
    Lang _lang;
    Eng _eng;
    Math _math;
};

bool nameCmp( All x, All y) {
    if(strcmp(x._name.name, y._name.name) < 0) return true;
    else return false;
}
bool langCmp( All x, All y) {
    return x._lang.lang > y._lang.lang;
}
bool engCmp( All x, All y) {
    return x._eng.eng < y._eng.eng;
}
bool mathCmp( All x, All y) {
    return x._math.math > y._math.math;
}

int main() {
    All s[100000];
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s %hhd %hhd %hhd", s[i]._name.name, &s[i]._lang.lang, &s[i]._eng.eng, &s[i]._math.math);
    }
    sort(s, s+n, nameCmp);
    sort(s, s+n, mathCmp);
    sort(s, s+n, engCmp);
    sort(s, s+n, langCmp);

    for(int i=0; i<n; i++) {
        printf("%s\n", s[i]._name.name);
    }
    return 0;
}
