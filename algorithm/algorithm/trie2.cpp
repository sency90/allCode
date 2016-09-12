#include <stdio.h>
#include <cstring>
using namespace std;
struct TrieNode{
    TrieNode* child[26];
    bool isTerminal;

    TrieNode() : isTerminal(false) {
        memset(child, NULL, sizeof(child));
    }

    ~TrieNode() {
        for(int i=0; i<26; i++) {
            if(child[i]) delete child[i];
        }
    }

    void insertNode(const char *str) {
        if(*str == 0) {
            isTerminal = true;
            return;
        }

        int next = *str-'A';
        if(child[next] == 0) child[next] = new TrieNode();
        child[next]->insertNode(str+1);
    }

    TrieNode* find(const char *str) {
        if(*str == 0) return this;
        if(isTerminal) return NULL;
        int next = *str-'A';
        if(next<0 || next>=26) return NULL;
        if(child[next]) return child[next]->find(str+1);
        else return NULL;
    }
};
int main() {
    TrieNode tn;
    tn.insertNode("DAG");
    if(tn.find("DAG")) printf("There is DAG!!\n");
    else puts("NO~!!!\n");
    return 0;
}
