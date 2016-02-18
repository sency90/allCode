#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct S{
    char name[11], l, e, m;
    void scan() {
        scanf("%s %hhd %hhd %hhd", name, &l, &e, &m);
    }
    bool operator<(const S& rhs) const {
        if(l == rhs.l) {
            if(e == rhs.e) {
                if(m == rhs.m) return strcmp(name, rhs.name) < 0;
                else return m > rhs.m;
            } else return e < rhs.e;
        } else return l > rhs.l;
    }
}s[100000];

int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) s[i].scan();
    sort(s, s+n);
    for(int i=0; i<n; i++) printf("%s\n", s[i].name);
    return 0;
}
