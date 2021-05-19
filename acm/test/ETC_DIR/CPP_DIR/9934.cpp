#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v;
int ar[1024];
int bi[11] = {1,2,4,8,16,32,64,128,256,512,1024};
int lim, idx = 0;
void inorder(int x) {
    if(x > lim) return;
    inorder(x*2);
    v.push_back(make_pair(x, ar[idx++]));
    inorder(x*2+1);
}
int main() {
    int n;
    scanf("%d", &n);
    lim = bi[n]-1;
    for(int i=0; i<lim; i++) {
        scanf("%d", &ar[i]);
    } inorder(1);

    int j=0, s=bi[0];
    sort(v.begin(), v.end());
    for(int i=1; i<=lim ;i++) {
        printf("%d ", v[i-1].second);
        if(i == s) {
            s+=bi[++j];
            printf("\n");
        }
    } return 0;
}
