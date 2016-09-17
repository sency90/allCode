#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
vector<int> getsfx(const string &s) {
    int n = s.size();
    vector<int> sfx(n), g(n+1), ng(n+1);
    int cnt[256], selOriIdx[256];
    for(int i=0; i<n; i++) {
        sfx[i]=i; //i번쨰 suffix가 s[i...]라고 일단 정하자. 정렬이 안된상태
        g[i]=s[i]; //각 suffix의 첫번째 글자를 기준으로 그룹을 지어준다.
    }
    g[n]=0; //마지막 문자의 그룹을 가장 작은수로 표시한다. 이 부분보다 큰 글자는 없기 떄문.
    for(int t=1; t<n; t<<=1) {
        //맨 처음에는 각 suffix의 첫 글자만 가지고 정렬이 되어있는데
        //이것을 t글자만큼 더 본 것을 가지고 정렬을 시도한다.
        //정렬방법은 counting sort이다.
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<256; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) selOriIdx[--cnt[g[min(i+t,n)]]] = i;

        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<256; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[selOriIdx[i]]]] = selOriIdx[i];

        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        ng[sfx[0]]=1;
        ng[n]=0;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g = ng;
    }
    return sfx;
}
int main() {
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    for(auto &p : sfx) {
        printf("%d: %s\n", p, s.c_str()+p);
    }
    return 0;
}
