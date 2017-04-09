#include <stdio.h>
#include <queue>
#include <vector>
#include <string>
struct Info{
    int d;
    char c;
    Info(int dd, char cc) {
        d=dd; c=cc;
    }
    bool operator<(const Info& rhs) const{
        return d > rhs.d;
    }
}
priority_queue<Info> mxh;
int main() {
    int t;
    scanf("%d", &t);
    for(int z=1; z<=t; z++) {
        int n, sum=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            sum+=d;
            mxh.push_back(Info(d,'A'+i));
        }
        Info tmp(0,0);
        while(sum>0) {
            if(sum==2) {
                tmp = mxh.top(); mxh.pop();
                if(tmp.d==2) s = s+tmp.c+tmp.c;
                else s = s+tmp.c+mxh.top().c;
            } else {

            }
        }
    }
    return 0;
}
