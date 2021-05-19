#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
string s[101];
struct Trie{
    Trie *room[26];
    Trie() {
        memset(room,0,sizeof(room));
    }
    ~Trie() {
        for(int i=0; i<26; i++) {
            if(room[i]) delete room[i];
        }
    }

    void push(char *s) {
        if(s[0]==0) return;

        char x = s[0]-'A';
        if(room[x]) room[x] = new Trie();
        room[x]->push(s+1);
    }
    int query(char *s) {
        if(s[0]==0) return 0;

        char x = s[0]-'A';
        if(room[x]) room[x]->query(s+1)+1;
        else return 0;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", s[i]);
    }

    int p,k;
    cin >> p >> k;
    char str[32];
    Trie tr;
    for(int i=0; i<p; i++) {
        scanf("%s", str);
        for(int j=0; str[j]; j++) {
            tr.push(str+j);
        }
        int len = strlen(str);
        reverse(str, str+len);
        for(int j=0; str[j]; j++) {
            tr.push(str+j);
        }
    }
    return 0;
}

