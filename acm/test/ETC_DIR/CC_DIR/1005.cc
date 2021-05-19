#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;
int v[1001], tm[1001];
vector<vector<int> > g;
vector<int> rpath;
bool chk[1001], valid[1001];
int w;
using namespace std;
class FastIO {
    int fd, bufsz;
    char *buf, *cur, *end;
    public:
    FastIO(int _fd = 0, int _bufsz = 1 << 20) : fd(_fd), bufsz(_bufsz) {
        buf = cur = end = new char[bufsz];
    }
    ~FastIO() { delete[] buf; }
    bool readbuf() {
        cur = buf;
        end = buf + bufsz;
        while (true) {
            size_t res = fread(cur, sizeof(char), end - cur, stdin);
            if (res == 0) break;
            cur += res;
        }
        end = cur;
        cur = buf;
        return buf != end;
    }
    int readint() {
        while (true) {
            if (cur == end) readbuf();
            if (isdigit(*cur) || *cur == '-') break;
            ++cur;
        }
        bool sign = true;
        if (*cur == '-') {
            sign = false;
            ++cur;
        }
        int ret = 0;
        while (true) {
            if (cur == end && !readbuf()) break;
            if (!isdigit(*cur)) break;
            ret = ret * 10 + (*cur - '0');
            ++cur;
        }
        return sign ? ret : -ret;
    }
};
bool dfs(int x) {
    chk[x]=true;
    if(x==w) {
        rpath.push_back(x);
        return valid[x]=true;
    }
    bool ret = false;
    for(auto &y: g[x]) {
        if(chk[y]) ret|=valid[y];
        else ret|=dfs(y);
    }
    if(ret) rpath.push_back(x);
    return valid[x]=ret;
}
int main() {
    FastIO fio;
    int tc=fio.readint();
    while(tc--) {
        rpath.clear();
        g.clear(); g.resize(1001, vector<int>());
        int n=fio.readint(), m=fio.readint();
        for(int i=1; i<=n; i++) v[i]=fio.readint();
        for(int i=0; i<m; i++) {
            int x=fio.readint(), y=fio.readint();
            g[x].push_back(y);
        }
        w=fio.readint();
        for(int i=1; i<=n; i++) {
            if(chk[i]) continue;
            dfs(i);
        }
        int ans=0;
        for(auto &p: rpath) {
            int mx=0;
            for(auto &q: g[p]) {
                if(valid[q]) mx=max(mx,tm[q]);
            }
            if(tm[p]<mx+v[p]) {
                tm[p]=mx+v[p];
                ans=max(ans,tm[p]);
            }
        }
        printf("%d\n", ans);
        memset(valid, false, sizeof(valid));
        memset(chk, false, sizeof(chk));
        memset(tm, 0, sizeof(tm));
    }
    return 0;
}
