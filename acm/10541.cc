#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
struct Query{
    long long line; char c; int idx;
    Query(){} Query(long long line, char c, int idx) :line(line),c(c),idx(idx) {}
    bool operator<(const Query &rhs) const {
        if(c == rhs.c) return line < rhs.line;
        else return c < rhs.c;
    }
};
vector<Query> query;
string s;
char pc=0;
long long pcnt[1000100];
long long f(int b, int e, char c) {
    int len = s.size();
    if(c!=pc) {
        memset(pcnt, 0, sizeof(pcnt));
        for(int i=0; i<len; i++) {
            if(s[i] == c) pcnt[i+1]=pcnt[i]+1LL;
            else pcnt[i+1] = pcnt[i];
        }
    }
    pc=c;
    return pcnt[e]-pcnt[b];
}
long long find(long long line, char c) {
    long long wb, we, len = s.size();
    if((line&1LL) == 0LL) {
        long long tmp = ((line>>1)%len);
        wb=(tmp*((line-1LL)%len))%len;
        we=(tmp*((line+1LL)%len))%len;
    } else {
        long long tmp = line%len;
        wb=((((line-1LL)>>1)%len)*tmp)%len;
        we=((((line+1LL)>>1)%len)*tmp)%len;
    }
    long long mid = line-((len-wb)+we);
    if(mid > 0LL) return f(wb,len,c) + (mid/len)*f(0LL,len,c) + f(0LL,we,c);
    else if(mid == 0LL) return f(wb,len,c) + f(0LL,we,c);
    else return f(wb, we, c);
}
int main() {
    ios::sync_with_stdio(false);
    int k;
    char c;
    long long n, line;
    cin >> n >> s >> k;
    for(int i=0; i<k; i++) {
        cin >> line >> c;
        query.push_back(Query(line,c,i));
    }
    sort(query.begin(), query.end());
    vector<pair<int, long long> > ans;
    for(int i=0; i<k; i++) {
        ans.push_back(make_pair(query[i].idx, find(query[i].line, query[i].c)));
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<k ;i++) {
        cout << ans[i].second << "\n";
    }
    return 0;
}
