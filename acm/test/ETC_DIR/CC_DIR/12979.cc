#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> > v;
int main() {
    int w,h,a;
    scanf("%d%d%d",&w,&h,&a);
    if(w>h) swap(w,h);
    for(int i=1; i*i<=a; i++) {
        if(a%i==0) {
            if(a/i<=w&&i<=h) v.push_back({a/i,i});
            if(i<=w&&a/i<=h) v.push_back({i,a/i});
        }
    }
    if(v.size()==0) {
        puts("-1");
        return 0;
    }
    int cnt, mn=0x3f3f3f3f;
    for(auto &p: v) {
        cnt=0;
        int x=p.first, y=p.second;
        while(x<w) {
            x*=2;
            cnt++;
        }
        while(y<h) {
            y*=2;
            cnt++;
        }
        if(mn>cnt) mn=cnt;
    }
    printf("%d", mn);
    return 0;
}
