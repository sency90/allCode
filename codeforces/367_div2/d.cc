#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
struct TrieNode{
    int cnt;
    TrieNode *room[2];
    TrieNode():cnt(0) {memset(room,0,sizeof(room));}
    ~TrieNode(){
        for(int i=0; i<2; i++) {
            if(room[i]) delete room[i];
        }
    }

    void ins(int d, int n) {
        cnt++;
        if(n<0) return;

        int t=d&(1<<n)?1:0;
        if(!room[t]) room[t] = new TrieNode();
        room[t]->ins(d,n-1);
    }

    void rm(int d, int n) {
        cnt--;
        if(n<0) return;
        int t = d&(1<<n)?1:0;
        room[t]->rm(d,n-1);
        if(room[t]->cnt == 0) {
            delete room[t];
            room[t]=nullptr;
        }
    }

    //방이 있는 쪽만 선택해서 골라왔기 때문에 room[0]이 nullptr이라면
    //room[1]은 반드시 존재한다. 반대로도 마찬가지
    int find(int d, int n) {
        if(n<0) return 0;
        int t = d&(1<<n)?1:0;
        if(room[t^1]) return (1<<n) + room[t^1]->find(d,n-1);
        else return room[t]->find(d,n-1);
    }
};
int main() {
    string type;
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, d;

    cin >> n;

    TrieNode *tn = new TrieNode();
    tn->ins(0,29);
    for(int i=0; i<n; i++) {
        cin >> type >> d;
        if(type=="+") tn->ins(d,29);
        else if(type=="-") tn->rm(d,29);
        else cout << tn->find(d,29) << "\n";
    }
    delete tn;
    return 0;
}
