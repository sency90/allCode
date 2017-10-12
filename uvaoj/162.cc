#include <iostream>
#include <deque>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
char card[3];
deque<char> player[2],deck;
void get(deque<char>& player, deque<char>& deck) {
    while(!deck.empty()) {
        player.push_back(deck.back()); deck.pop_back();
    }
}
int face(char c) {
    if(c=='J') return 1;
    else if(c=='Q') return 2;
    else if(c=='K') return 3;
    else if(c=='A') return 4;
    else return 0;
}
int main() {
    while(true) {
        player[0].clear(); player[1].clear(); deck.clear();
        for(int t=1,i=0; i<52; t^=1, i++) {
            scanf("%s", card);
            if(card[0]=='#') return 0;
            player[t].push_front(card[1]);
        }

        int cnt=0,t=1;
        for(;!player[t].empty();) {
            char c = player[t].front(); player[t].pop_front();
            deck.push_front(c);
            int num = face(c);
            if(num) t^=1, cnt=num;
            else if(cnt) {
                if(--cnt == 0) {
                    t^=1;
                    get(player[t],deck);
                }
            } else t^=1;
        }
        t^=1;
        printf("%d%3lu\n",t+1, player[t].size());
    }
    return 0;
}
