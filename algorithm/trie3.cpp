#include <iostream>
#include <cstring>
using namespace std;
struct TrieNode{
    TrieNode* child[26]; //lowercase 26
    bool isTerminal;

    TrieNode() : isTerminal(false) {
        memset(child, 0, sizeof(child));
    }
    ~TrieNode() {
        for(int i=0; i<26; i++) {
            if(child[i]) delete child[i];
        }
    }

    void insert(const char* str) {
        if(*str == 0) {
            isTerminal = true;
            return;
        }
        int next = *str-'a';
        if(next<0 || next>=26) {
            cerr << "ERROR!\n";
            return;
        }
        if(child[next] == 0) child[next] = new TrieNode();
        child[next]->insert(str+1);
    }

    TrieNode* find(const char* str) {
        if(*str == 0) return this;
        int next = *str-'a';
        if(next<0 || next>=26) return NULL;
        if(child[next] == 0) return NULL;
        else return child[next]->find(str+1);
    }
};
int main() {
    TrieNode tn;
    tn.insert("dog");
    if(tn.find("dog")) cout << "There is a \'dog\'\n";
    return 0;
}
