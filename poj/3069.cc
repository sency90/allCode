#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int r,n;
    while(true) {
        scanf("%d%d",&r,&n);
        if(r==-1 && n==-1) return 0;
        else v.clear();
        for(int i=0; i<n; i++) {
            int d; scanf("%d", &d);
            v.push_back(d);
        }
        sort(v.begin(), v.end());
        if(r==0) {
            v.erase(unique(v.begin(), v.end()), v.end());
            printf("%lu\n", v.size());
        } else {
            int s=0, cnt=0;
            while(true) {
                vector<int>::iterator it = upper_bound(v.begin()+s, v.end(), v[s]+r);
                it--;
                int idx = it-v.begin();
                vector<int>::iterator jt = upper_bound(v.begin(), v.end(), v[idx]+r);
                cnt++;
                if(jt==v.end()) break;
                else s=jt-v.begin();
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}
