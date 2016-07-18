#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct TrieNode{
    TrieNode* child[26];
    int idx;
    bool isTerminal;
    char cnt;
    TrieNode() : isTerminal(false), cnt(0), idx(-1) {
        memset(child, 0, sizeof(child));
    }
    ~TrieNode() {
        for(int i=0; i<26; i++) if(child[i]) delete child[i];
    }
    void insert(const char* str, int idx) {
        if(this->idx == -1) this->idx = idx;
        if(*str == 0) {
            isTerminal = true;
            return;
        }
        int next = *str-'A';
        if(child[next] == 0) {
            child[next] = new TrieNode();
            cnt++;
        }
        child[next]->insert(str+1, idx);
    }

    int find(const char* str) {
        if(*str == 0) {
            if(isTerminal) return -1; //ans
            else return -2; //there ins't an answer
        }
        int next = *str-'A';
        if(child[next] == 0) return -2;
        int tmp = child[next]->find(str+1);
        if(tmp == -2) return tmp;
        else if(tmp == -1) {
            if(cnt >= 2) return 1;
            else return tmp;
        } else return tmp+1;
    }
};

struct String{
    string s;
    int pr;
    String(){} String(string s, int pr) : s(s), pr(pr) {}
    bool operator<(const String &rhs) const{
        if(pr == rhs.pr) return s < rhs.s;
        else return pr > rhs.pr;
    }
};
String str[10000];
int main() {
    ios::sync_with_stdio(false);
    int t,n,m,pr,cnt=0;
    TrieNode tn;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >> str[i].s >> str[i].pr;
            tn.insert(str[i].s.c_str());
        }
        string s;
        for(int i=0; i<m; i++) {
            cin >> s;
            int tmp = tn.find(s.c_str());
            if(tmp < 0) cnt+=s.size();
            else cnt+=tmp+1;
            cnt++; //space
        }
        cnt--; //space
        cout << cnt << "\n";
    }
    return 0;
}
