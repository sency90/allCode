#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cassert>
using namespace std;
int v[100001];
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



struct Trie{
    Trie *room[2];
    Trie(){
        room[0] = NULL;
        room[1] = NULL;
    }
    ~Trie() {
        for(int i=0; i<2; i++) {
            if(room[i]) delete room[i];
        }
    }
    void push(int bit, int pos) {
        if(pos<0)  return;
        int x = (bit >> pos) & 1;
        if(!room[x]) room[x]=new Trie();
        room[x]->push(bit, pos-1);
    }
    int find(int bit, int pos) {
        if(pos<0) return 0;
        int x = (bit >> pos) & 1;
        if(room[x^1]) return (1 << pos) + (room[x^1]->find(bit,pos-1));
        return room[x]->find(bit, pos-1);
    }
};
int main() {
    FastIO fio;
    int tc=fio.readint();
    scanf("%d",&tc);
    while(tc--){
        Trie tr;
        int n=fio.readint();
        scanf("%d",&n);
        memset(v,0,sizeof(v));
        int ans=0;
        tr.push(v[0],30);
        for(int i=1; i<=n; i++) {
            v[i]=fio.readint();
            v[i]^=v[i-1];
            tr.push(v[i],30);
            ans = max(ans,tr.find(v[i],30));
        }
        printf("%d\n", ans);
    }
    return 0;
}
