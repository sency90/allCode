#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> v, w;
void factor(int x) {
    for(int i=1; i*i<=x; i++) {
        if(x%i==0) {
            w.push_back(i);
            if(x/i != i) w.push_back(x/i);
        }
    }
    sort(w.begin(), w.end());
}
int main() {
    int n,pj=0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    factor(v[n-1]);
    for(int i=0; i<n-1; i++) {
        for(int j=pj; j<w.size(); j++) {
            if(v[i] == w[j]) {
                pj=j+1;
                break;
            }
            else if(v[i] < w[j]) {
                if(v[i]-(v[i+1]%v[i]) <= v[0]) {
                    pj=j+1;
                    break;
                }
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
