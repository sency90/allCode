#include <iostream>
#include <vector>
using namespace std;
vector<int> v[2];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        v[0].push_back(1);
    }
    for(int i=0,t=0,p=0,c=0; i<n; i++, t^=1, p+=2) {
        for(int j=0; j<p; j++) putchar(' ');
        v[t^1].clear();
        for(int j=i,k=0; j<n; j++,k++) {
            if(j!=n-1) c++;
            printf("%3d ", v[t][k]);
            v[t^1].push_back((v[t][k]+((c&1)?1:-1)*v[t][k+1]));
        }
        puts("");
    }
    return 0;
}
