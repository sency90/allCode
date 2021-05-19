#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int v[100001];
//map<int,int> mp[31];
struct Trie{
    Trie *room[2];
    bool isTerminal;
    Trie():isTerminal(false){
        memset(room,0,sizeof(room));
    }
    ~Trie() {
        for(int i=0; i<2; i++) {
            if(room[i]) delete room[i];
        }
    }
    void push(int bit, int pos) {
        if(pos<0) {
            isTerminal=true;
            return;
        }

        int x = bool(bit&(1<<pos));
        if(!room[x]) room[x]=new Trie();
        room[x]->push(bit, pos-1);
    }
    int find(int bit, int pos, int nbit) {
        if(pos<0) return nbit;
        int x = bool(bit&(1<<pos));
        int resa=0, resb=0;
        if(room[x^1]) resb = bit^(room[x^1]->find(bit,pos-1,nbit|((x^1)<<pos)));
        else if(room[x]) resa = bit^(room[x]->find(bit,pos-1,nbit|(x<<pos)));
        else {
            if(pos==0) return nbit;
            else return (bit&((1<<(pos))-1))|nbit;
        }
        return max(resa,resb);
    }
};
int main() {
    int tc; scanf("%d", &tc);
    while(tc--){
        Trie tr;
        int n;
        scanf("%d", &n);
        memset(v,0,sizeof(v));
        tr.push(v[0],30);
        for(int i=1; i<=n; i++) {
            scanf("%d", &v[i]);
            v[i]^=v[i-1];
            tr.push(v[i],30);
        }
        int ans = 0;
        for(int i=0; i<=n; i++) {
            ans = max(ans,tr.find(v[i],30,0));
        }
        printf("%d\n", ans);
    }
    return 0;
}


