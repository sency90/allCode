#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
string bin(int x) {
    string s;
    while(x!=0) {
        s=(char)('0'+(x&1))+s;
        x>>=1;
    }
    while(s.size()!=30) s='0'+s;
    return s;
}
struct TrieNode{
    TrieNode *room[2];
    int cnt;
    TrieNode():cnt(0){memset(room,0,sizeof(room));};

    void ins(const char *s) {
        cnt++;
        if(s[0]==0) return;

        int t=*s-'0';
        if(room[t]==NULL) room[t] = new TrieNode();
        room[t]->ins(s+1);
    }

    bool remove(const char *s, bool chg) {
        cnt--;
        if(*s==0) {
            if(cnt==0) return chg&true;
            else return false;
        }

        int t = *s-'0';
        if(room[t]->remove(s+1,chg?true:t)) {
            delete room[t];
            room[t]=0;
            if(cnt == 0) return true;
        }
        return false;
    }

    int find(const char *s, int n, bool chg) {
        if(n==-1) {
            if(!chg) return 1;
            else return 0;
        }

        if(!chg) {
            if(*s=='1') return (1<<n) + room[0]->find(s+1,n-1,true);
            else {
                if(room[1]) return (1<<n) + room[1]->find(s+1,n-1,true);
                else return room[0]->find(s+1,n-1,false);
            }
        } else {
            if(*s=='1') {
                if(room[0]) return (1<<n) + room[0]->find(s+1,n-1,chg);
                else if(room[1]) return room[1]->find(s+1,n-1,chg);
                else return 0;
            } else {
                if(room[1]) return (1<<n) + room[1]->find(s+1,n-1,chg);
                else if(room[0]) return room[0]->find(s+1,n-1,chg);
                else return 0;
            }
        }
    }
};
int main() {
    TrieNode tn;
    tn.ins("000000000000000000000000000000");

    string type, s;
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int d;
        cin >> type >> d;
        s = bin(d);
        if(type=="+") tn.ins(s.c_str());
        else if(type=="-") tn.remove(s.c_str(),false);
        else printf("%d\n", tn.find(s.c_str(),29,false));
    }
    return 0;
}
