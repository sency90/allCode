#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
struct TrieNode{
    TrieNode *room[26];
    bool isTerminal;
    TrieNode():isTerminal(false){
        memset(room, 0, sizeof(room));
    }
    ~TrieNode() {
        for(int i=0; i<26; i++) {
            if(room[i]) delete room[i];
        }
    }
    void insert(const char *s) {
        if(*s==0) {
            isTerminal=true;
            return;
        }
        int x = *s-'a';
        if(!room[x]) room[x]=new TrieNode();
        room[x]->insert(s+1);
    }
    TrieNode* find(const char *s) {
        if(*s==0) {
            if(isTerminal) return this;
            else return nullptr;
        }
        int x=s[0]-'a';
        if(room[x]) return room[x]->find(s+1);
        else return nullptr;
    }
};
int main() {
    TrieNode tn;
    tn.insert("dog");
    if(tn.find("dog")) puts("There is a dog");
    else puts("There isn't a dog");
    return 0;
}
