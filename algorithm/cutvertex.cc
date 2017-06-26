#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
vector<int> v[101], cv;
void e(int x, int y) { v[x].push_back(y); v[y].push_back(x); }
int discov[101], C=0;
int dfs(int x) {
    int ret = discov[x]=++C, treeEdge=0;
    for(int y: v[x]) {
        if(discov[y]) ret = min(ret, discov[y]);
        else {
            treeEdge++;
            int subtree = dfs(y);
            ret = min(ret, subtree);
            if(discov[x]!=1 && subtree>=discov[x]) cv.push_back(x);
        }
    }
    if(discov[x]==1 && treeEdge>=2) cv.push_back(x);
    return ret;
}
int main() {
    //e(1,2);
    //e(2,3);
    e(0,1); e(0,4); e(0,5); e(0,6);
    e(5,3); e(5,6);

    e(6,3); e(4,2); e(1,2); e(2,0);

    dfs(1);
    printf("cut vertex: ");
    for(int i: cv) printf("%d ", i);
    puts("");
    return 0;
}
