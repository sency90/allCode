#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#define CHARNUM 54
using namespace std;
int chg(char x) {
    if(isupper(x)) return x-'A'+27;
    else return x-'a'+1;
}
vector<int> getsfx(const string &s) {
    int n = s.size();
    int lim = max(n+1,CHARNUM);
    vector<int> sfx(n), g(n+1), ng(n+1), aux(n+1), cnt;
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=chg(s[i]);
    }
    g[n]=0; //이 부분을 안쓰면 ZZZZZZZZZZZZZZZZ... 입력에 대해 error발생
    for(int t=1; t<n; t<<=1) {

        //26,33,34번째 줄에서 counting sort를 한다. 기준 인덱스로부터 t만큼 떨어진 곳을 기준으로 정렬한다.
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        //lim이 54가 아닌 max(n+1, 54)인 이유:
        //cnt[]에 인덱스로 들어가는 값은 group의 개수이다.
        //여기서 그룹의 개수가 알파벳 수만큼이라고 착각하기 쉬운데,
        //문자열 길이가 600이 되면 suffix도 600개나 나온다.
        //결국 모든 그룹은 나중에 전부 분류가 되니까 600개나 나올 수밖에 없다.
        //따라서 lim은 max(n+1,54)가 되어야 한다.
        for(int i=1; i<lim; i++) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--) aux[--cnt[g[min(i+t,n)]]]=i;

        //38,39,40번째 줄에서 다시 counting sort를 한다.
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<lim; i++) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[aux[i]]]]=aux[i];

        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        ng[sfx[0]]=1;
        ng[n]=0;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]] = ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g = ng;
    }
    return sfx;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    for(auto &p : sfx) {
        printf("%d ", p);
    } puts("");
    return 0;
}
