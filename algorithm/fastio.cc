#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
class FastIO{
    int fd,bufsz;
    char *buf,*cur,*end;
    public:
    FastIO(int fd=0, int bufsz=(1<<20)):fd(fd),bufsz(bufsz) {
        buf=cur=end=new char[bufsz];
    }
    ~FastIO() { delete[] buf; }
    bool readbuf() {
        cur=buf;
        end=buf+bufsz;
        while(true) {
            size_t res=fread(cur,sizeof(char),end-cur,stdin);
            if(res==0) break;
            cur+=res;
        }
        end=cur;
        cur=buf;
        return buf!=end;
    }
    int readint() {
        while(true) {
            if(cur==end) readbuf();
            if(isdigit(*cur)||*cur=='-') break;
            ++cur;
        }
        bool sign=true;
        if (*cur=='-') {
            sign=false;
            ++cur;
        }
        int ret=0;
        while(true) {
            if(cur==end && !readbuf()) break;
            if(!isdigit(*cur)) break;
            ret=ret*10+(*cur-'0');
            ++cur;
        }
        return sign?ret:-ret;
    }
};

int main() {
    FastIO fio;
    int tc = fio.readint();
    while(tc--) {
        int mxs=0, mxb=0,s,b;
        int l=fio.readint(), n=fio.readint(), x;
        for(int i=0; i<n; i++) {
            x=fio.readint();
            s=x; b=l-x;
            if(s>b) swap(s,b);
            mxs = max(mxs, s);
            mxb = max(mxb, b);
        }
        printf("%d %d\n",mxs,mxb);
    }
    return 0;
}
