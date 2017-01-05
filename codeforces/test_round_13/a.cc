#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n;
    scanf("%d", &n);
    int ans=0;
    for(int i=0; i<50; i++) {
        if(i*(i+1)/2 <= n && n < (i+1)*(i+2)/2) {
            ans=i;
            break;
        }
    }
    for(int i=1; i<=ans; i++) {
        v.push_back(i);
    }
    int x = ans*(ans+1)/2;
    int dif = n-x;
    for(int i=v.size()-1, j=0; j<dif; i--,j++) {
        v[i]++;
    }
    printf("%lu\n",v.size());
    for(int p: v) printf("%d ", p);
    return 0;
}
