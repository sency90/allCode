#include <stdio.h>
#include <vector>
using namespace std;
void pick(vector<int>& picked, int n, int c) {
    if(c==0) {
        for(int i=0; i<picked.size(); i++) {
            printf("%d ", picked[i]);
        }
        puts("");
    }
    int s = picked.empty()? 0:picked.back()+1;
    for(int i=s; i<n; i++) {
        picked.push_back(i);
        pick(picked, n, c-1);
        picked.pop_back();
    }
}
int main() {
    int n, c;
    scanf("%d%d",&n,&c);
    vector<int> v;
    pick(v,n,c);
    return 0;
}
