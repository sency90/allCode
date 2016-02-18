#include <stdio.h>
#include <vector>
using namespace std;
int k;
vector<int> v;
int calc(vector<int>& orig, int prevSize) {
    //l.clear();
    //r.clear();
    vector<int> l, r;
    v = orig;
    int cnt=0;
    int len = v.size();
    int mid = k-prevSize;
    for(int i=0; i<len; i++) {
        if(mid == i) continue;
        else if(v[i] < v[mid]) {
            l.push_back(v[i]);
            cnt++;
        } else r.push_back(v[i]);
    }
    if(cnt+prevSize == k) return v[cnt];
    else if(cnt+prevSize > k) return calc(l, prevSize);
    else return calc(r, prevSize+l.size());
}
int main() {
    vector<int> v;
    int n, in;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &in);
        v.push_back(in);
    }
    printf("%d\n", calc(v, 0));
    return 0;
}
