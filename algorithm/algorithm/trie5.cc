#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct TrieNode{
    TrieNode *c[26];
    bool isTerminal;
    TrieNode() {
        isTerminal = false;
        memset(c, 0, sizeof(c));
    }
    ~TrieNode() {
        for(int i=0; i<26; i++) {
            if(c[i]) delete c[i];
        }
    }

    void ins(const string &s) {
        if(s.size() == 0) {
            isTerminal = true;
            return;
        }
        if(c[s[0]-'A']) c[s[0]-'A']->ins(s.c_str()+1);
        else {
            c[s[0]-'A'] = new TrieNode();
            c[s[0]-'A']->ins(s.c_str()+1);
        }
    }

    TrieNode* find(const string &s) {
        if(s.size() == 0) {
            if(isTerminal) return this;
            else return NULL;
        } else {
            if(c[s[0]-'A']) return c[s[0]-'A']->find(s.c_str()+1);
            else return NULL;
        }
    }
};

int main() {
    int n;
    ios::sync_with_stdio(false);
    string str;
    TrieNode trie;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str;
        trie.ins(str);
    }

    if(trie.find("DAG")) puts("There is a DAG string.");
    else puts("There isn't a DAG string.");
    return 0;
}
