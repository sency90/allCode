#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define NONE -1
struct TrieNode {
    int term, id;
    bool isFirst;
    TrieNode *c[26];
    TrieNode() : term(-1), id(-1), isFirst(true) {
        memset(c, 0, sizeof(c));
    }
    ~TrieNode() {
        for(int i=0; i<26; i++) {
            if(c[i]) delete c[i];
        }
    }

    int toNum(char c) { return c-'A'; }
    void ins(const string &str, int id) {
        if(isFirst) {
            isFirst = false;
            this->id = id;
        }
        if(str.size() == 0) {
            term = id;
            return;
        } else {
            int next = toNum(str[0]);
            if(c[next]) c[next]->ins(str.c_str()+1, id);
            else {
                c[next] = new TrieNode();
                c[next]->ins(str.c_str()+1, id);
            }
        }
    }

    TrieNode* find(const string &str) {
        if(str.size()==0) {
            if(term==-1) return NULL;
            else return this;
        } else {
            int next = toNum(str[0]);
            if(c[next]) return c[next]->find(str.c_str()+1);
            else return NULL;
        }
    }

    int type(const string &str, int id) {
        if(str.size()==0) {
            if(term==id) return 0;
            else return NONE;
        } else {
            if(this->id == id) return 1;
            else {
                int next = toNum(str[0]);
                if(c[next]) return 1 + c[next]->type(str.c_str()+1, id);
                else return NONE;
            }
        }
    }
};
struct Info{
    char str[11];
    int p;
    bool operator<(const Info &rhs) const {
        if(p == rhs.p) return strcmp(str, rhs.str) < 0;
        else return p > rhs.p;
    }
}info[10000];
int main() {
    int tc,n,m;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) {
            scanf("%s%d",info[i].str,&info[i].p);
        }
        sort(info, info+n);
        TrieNode tn;
        for(int i=0; i<n; i++) {
            tn.ins(info[i].str, i);
        }

        int cnt=0;
        char str[20001];
        while(scanf("%s", str)!=EOF) {
            TrieNode* t = tn.find(str);
            if(t==NULL || t->term==NONE) cnt+=strlen(str);
            else cnt+=tn.type(str, t->term);
            cnt++;
        }
        cnt--;
        printf("%d\n", cnt);
    }
    return 0;
}
