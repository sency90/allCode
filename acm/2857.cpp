#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
    char ppc, pc, c;
    int i=0;
    while(true) {
        ++i; ppc=0; pc=0;
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(ppc=='F' && pc=='B' && c=='I') v.push_back(i);
            ppc = pc; pc = c;
        }
        if(c==EOF) break;
    }
    if(v.empty()) {
        printf("HE GOT AWAY!");
        return 0;
    }
    sort(v.begin(), v.end());
    for(i=0; i<v.size(); i++) printf("%d ", v[i]);
    return 0;
}
