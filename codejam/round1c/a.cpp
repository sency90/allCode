#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct Info{
    int x;
    char c;
    Info(int xx, char cc) {
        x=xx; c=cc;
    }
    bool operator<(const Info &rhs) const {
        return x < rhs.x;
    }
};
priority_queue<Info> mxh;
int main() {
    freopen("asin.txt", "r", stdin);
    freopen("asout.txt", "w", stdout);
    int t, n, d, sum;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        sum = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            sum+=d;
            mxh.push(Info(d,'A'+i));
        }
        Info tmp(0,0);
        string s;
        while(sum>0) {
            if(sum==2) {
                tmp = mxh.top(); mxh.pop();
                s=s+tmp.c+mxh.top().c; mxh.pop();
                break;
            }
            tmp = mxh.top(); mxh.pop();
            /*
               if((tmp.x-2)*2 <= (sum-2) && sum>2 && tmp.x>2) {
               sum-=2;
               s = s+tmp.c+tmp.c+' ';
               if(tmp.x-2 != 0) mxh.push(Info(tmp.x-2, tmp.c));
               } else {
               */

            sum-=1;
            s += tmp.c;
            s += ' ';
            if(tmp.x-1 != 0) mxh.push(Info(tmp.x-1, tmp.c));

        }
        cout << "Case #" << i << ": " << s << '\n';
        }
        fclose(stdin);
        return 0;
    }
