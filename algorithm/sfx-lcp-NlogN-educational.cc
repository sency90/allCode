//Suffix Array & LCP. Made by plzrun.
//prev_sfx_str[a] = b는 str[a...]라는 suffix 바로 앞에오는 suffix가 str[b...]라는 뜻
//PLCP는 permuted LCP의 약자임.
//PLCP[i]는 str[i...]를 x번째 suffix(즉, sfx[x]는 i라는 뜻)라 했을 때 x-1번째 suffix(sfx[x-1])의 common prefix의 길이를 의미한다.
//PLCP자체만으로 LCP값이 들어간 것이지만 PLCP[i]에서의 i값이 suffix의 순서가 아닌 문자열의 순서로 들어가 있음.
//그러므로 이를 suffix array의 순서로 바꾸면
//LCP[x] = PLCP[sfx[x]]; 이다.
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
vector<int> lcp;
vector<int> getsfx(const string &s) {
    const int n = s.size();
    lcp.clear(); lcp.resize(n);
    int lim = max(n+1, 256);
    vector<int> sfx(n), g(n+1,0), ng(n+1,0), cnt, idx(n+1,0);
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=s[i];
    }
    g[n]=0; //이 부분을 안쓰면 ZZZZZZZZZZZZZZZZZZ... 입력에 대해 error발생
    for(int t=1; t<n; t<<=1) {
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[--cnt[g[min(i+t,n)]]]=i;

        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[idx[i]]]]=idx[i];

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
        g=ng;
    }
    vector<int> prev_sfx_str(n+1), plcp(n+1);
    prev_sfx_str[sfx[0]]=-1;
    for(int i=1; i<n; i++) prev_sfx_str[sfx[i]]=sfx[i-1];
    for(int i=0, common=0; i<n; i++) {
        if(prev_sfx_str[i]==-1) plcp[i]=0;
        else {
            while(s[i+common] == s[prev_sfx_str[i] + common]) common++;
            plcp[i]=common;
            common = max(common-1,0);
        }
    }
    for(int i=0; i<n; i++) lcp[i]=plcp[sfx[i]];
    return sfx;
}
int main() {
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    printf("sfx: ");
    for(auto &p : sfx) {
        printf("%d ", p);
    }
    printf("\nlcp: ");
    for(auto &p : lcp) {
        printf("%d ", p);
    }
    puts("");
    return 0;
}

