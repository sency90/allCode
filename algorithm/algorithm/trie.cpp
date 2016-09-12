#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
//알파벳 대문자를 저장하는 경우 각 노드는 26개의 child를 가질 수 있다.
const int ALPHABETS = 26;
int toNumber(char ch) {
    return ch-'A';
}

struct TrieNode{
    TrieNode* children[ALPHABETS];

    //이 노드가 종료노드인가?
    bool terminal;
    TrieNode() : terminal(false) {
        memset(children, 0, sizeof(children));
    }

    ~TrieNode() {
        for(int i=0; i<ALPHABETS; i++) {
            if(children[i]) { //children[i]에 주소가 있으면 (처음에 memset으로 children의 주소를 0으로 초기화 하는구만)
                delete children[i];
            }
        }
        puts("");
    }

    //이 노드를 루트로 하는 트라이에 문자열 key를 추가한다.
    void insert(const char* key) {
        //문자열이 끝나면 terminal만 참으로 바꾸고 종료
        if(*key == 0) terminal = true;
        else {
            int next = toNumber(*key);

            //해당 자식 노드가 없다면 생성한다.
            if(children[next] == NULL) children[next] = new TrieNode();

            //해당 자식 노드로 재귀 호출
            children[next]->insert(key+1);
        }
    }

    //이 노드를 루트로 하는 트라이에 문자열 key와 대응되는 노드를 찾는다.
    //없으면 NULL을 return한다.
    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        int next = toNumber(*key);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key+1);
    }

};
char s[100];
int main() {
    int n,m;
    TrieNode tn;
    ios::sync_with_stdio(false);
    memset(s, 0, sizeof(s));

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        tn.insert(s);
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> s;
        if(tn.find(s)) cout << s << " FOUND!!";
        else cout << s << " NOT FOUND!!";
    }
    return 0;
}
