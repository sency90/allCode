#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;
struct TrieNode{
    TrieNode* child[52];
    bool isTerminal;

    TrieNode() : isTerminal(false) {
        memset(child, 0, sizeof(child));
    }
    ~TrieNode() {
        for(int i=0; i<52; i++) {
            if(child[i]) delete child[i];
        }
    }

    void insert(const char* str) {
        if(*str == 0) return;

        int next;
        if(islower(*str)) next = *str-'a';
        else if(isupper(*str)) next = *str-'A'+26;
        else {
            cerr << "ERROR!!!\n";
            exit(-1);
        }

        if(child[next] == 0) child[next] = new TrieNode();
        child[next]->insert(str+1);
    }

    TrieNode* find(const char* str) {
        if(*str == 0) return this;

        int next;
        if(islower(*str)) next = *str-'a';
        else if(isupper(*str)) next = *str-'A'+26;
        else {
            cerr << "ERROR!!!\n";
            exit(-1);
        }

        if(child[next] == 0) return NULL;
        else return child[next]->find(str+1);
    }
};
int main() {
    TrieNode tn;
    string s = "dog";
    tn.insert(s.c_str());
    if(tn.find("dog")) cout << "There is a " << s << ".\n";
    else cout << "There isn't a " << s << ".\n";
    return 0;
}
