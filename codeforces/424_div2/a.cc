#include <iostream>
using namespace std;
int v[101];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int phase, p_phase=-1;
    for(int i=1; i<n; i++) {
        if(v[i-1]<v[i]) phase=1;
        else if(v[i-1]==v[i]) phase=2;
        else phase=3;

        if(p_phase>phase) return 0&puts("NO");
        p_phase=phase;
    }
    puts("YES");
    return 0;
}
