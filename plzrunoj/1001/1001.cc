#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v;
char title[10];
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n,idx=0;
    while(~scanf("%d",&n)) {
        idx++;
        sprintf(title, "%d.in", idx);
        FILE *inf = fopen(title, "w");
        fprintf(inf, "%d\n", n);

        v.clear(); v.resize(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
            fprintf(inf, "%d ", v[i]);
        }
        fclose(inf);

        sprintf(title, "%d.out", idx);
        FILE *outf = fopen(title, "w");
        sort(v.begin(), v.end());
        for(int k=0; k<=n; k++) {
            auto it = lower_bound(v.begin(), v.end(), k);
            int l=v.end()-it;
            if(l>=k && v[n-k-1]<=k) {
                fprintf(outf, "%d\n", k);
                break;
            }
        }
        fclose(outf);
    }
    return 0;
}
