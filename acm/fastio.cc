#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
class FastIO {
    int fd, bufsz;
    char *buf, *cur, *end;
    public:
    FastIO(int _fd = 0, int _bufsz = 1 << 25) : fd(_fd), bufsz(_bufsz) {
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
        int ret = 0;
        while (true) {
            if (cur == end && !readbuf()) break;
            if (!isdigit(*cur)) break;
            ret = ret * 10 + (*cur - '0');
            ++cur;
        }
        return ret;
    }
    ll readll() {
        while(true) {
            if(cur==end) readbuf();
            if(isdigit(*cur)) break;
            ++cur;
        }
        ll ret=0LL;
        while(true) {
            if(cur==end&&!readbuf()) break;
            if(!isdigit(*cur)) break;
            ret = ret*10LL+(*cur-'0');
            ++cur;
        }
        return ret;
    }
};

int main() {
    FastIO fio;
    int i,n = fio.readint();
    ll sum=0LL, x;
    for(i=0; i<n; i++) {
        x=fio.readll();
        sum+=x;
    }
    printf("%d\n%lld\n",i,sum);
    return 0;
}
