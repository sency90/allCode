#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef unsigned int uint;
typedef pair<int,int> pii;
char order_shape[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
int order[256];
struct Card{
    string shape;
    Card(){} Card(const string &shape):shape(shape){}
    bool operator<(const Card &rhs) const {
        return order[uint(shape[0])] < order[uint(rhs.shape[0])];
    }
    bool operator==(const Card &rhs) const {
        return order[uint(shape[0])] == order[uint(rhs.shape[0])];
    }
    bool operator>(const Card &rhs) const {
        return order[uint(shape[0])] > order[uint(rhs.shape[0])];
    }
    bool operator!=(const Card &rhs) const {
        return !(*this==(rhs));
    }
};
struct Deck{
    Card card[5];
    int pos;
    Deck(){}
    void sort() {
        std::sort(card, card+5);
    }
    int getPos() const {
        return pos;
    }
    pii findOnePair() const {
        for(int i=0; i<5; i++) {
            for(int j=i+1; j<5; j++) {
                if(card[i] == card[j]) {
                    return pii(i,j);
                }
            }
        }
        return pii(0,0); //unreachable code
    }
    int findNotTwoPair() const {
        pii p = findOnePair();
        for(int i=0; i<5; i++) {
            if(i==p.first || i==p.second) continue;
            for(int j=i+1; j<5; j++) {
                if(j==p.first || j==p.second) continue;
                if(card[i] == card[j]) {
                    for(int k=0; k<5; k++) {
                        if(!(k==p.first || k==p.second || k==i || k==j)) {
                            return k;
                        }
                    }
                }
            }
        }
        return 0; //unreachable code
    }
    int findThreeCard() const {
        for(int i=0; i<5; i++) {
            for(int j=i+1; j<5; j++) {
                if(card[i]==card[j]) return i;
            }
        }
        return 0; //unreachable code
    }
    pii findFullHouseGroup() const {
        for(int i=0; i<5; i++) {
            for(int j=i+1; j<5; j++) {
                for(int k=j+1; j<5; j++) {
                    if(card[i]==card[j] && card[j]==card[k]) {
                        for(int u=0; u<5; u++) {
                            if(u!=i && u!=j && u!=k) {
                                return pii(i,u);
                            }
                        }
                    }
                }
            }
        }
        return pii(0,0); //unreachable code
    }
    int findFourCard() const {
        for(int i=0; i<5; i++) {
            for(int j=i+1; j<5; j++) {
                if(card[i]==card[j]) return i;
            }
        }
        return 0; //unreachable code
    }
    bool operator<(const Deck &rhs) const {
        //high_card, one_pair, two_pair, three_card, straight, flush, full_house, four_card, straight_flush
        //0          1         2         3           4         5      6           7          8
        int lhsPos = this->getPos(), rhsPos = rhs.getPos();
        if(lhsPos == rhsPos) {
            if(lhsPos == 0) { //high card
                if(card[4] == rhs.card[4]) {
                    if(card[3] == rhs.card[3]) {
                        if(card[2] == rhs.card[2]) {
                            if(card[1] == rhs.card[1]) {
                                return card[0] < rhs.card[0];
                            } else return card[1] < rhs.card[1];
                        } else return card[2] < rhs.card[2];
                    } else return card[3] < rhs.card[3];
                } else return card[4] < rhs.card[4];
            } else if(lhsPos == 1) { //one pair
                pii lhsPair = findOnePair(), rhsPair = rhs.findOnePair();
                if(card[lhsPair.first] == rhs.card[rhsPair.first]) {
                    int tmp[3], rhstmp[3], cnt=0, rhscnt=0;
                    for(int i=0; i<5; i++) {
                        if(i!=lhsPair.first && i!=lhsPair.second) tmp[cnt++] = i;
                        if(i!=rhsPair.first && i!=rhsPair.second) rhstmp[rhscnt++] = i;
                    }
                    for(int i=2; i>=0; i--) {
                        if(card[tmp[i]] == rhs.card[rhstmp[i]]) continue;
                        return card[tmp[i]] < rhs.card[rhstmp[i]];
                    }
                } else return card[lhsPair.first] < rhs.card[rhsPair.first];
                return false;
            } else if(lhsPos == 2) { //two pair
                int lhsNot = findNotTwoPair(), rhsNot = rhs.findNotTwoPair();
                int mx=-1, mxi1=0, mxi2=0, rhsmx=-1, rhsmxi1=0, rhsmxi2=0;
                for(int i=0; i<5; i++) {
                    if(i!=lhsNot) {
                        if(mx<order[uint(card[i].shape[0])]) {
                            if(mx!=-1) mxi1 = i;
                            else mxi2 = i;
                            mx = order[uint(card[i].shape[0])];
                        }
                    }

                    if(i!=rhsNot) {
                        if(rhsmx<order[uint(rhs.card[i].shape[0])]) {
                            if(rhsmx!=-1) rhsmxi1 = i;
                            else rhsmxi2 = i;
                            rhsmx = order[uint(rhs.card[i].shape[0])];
                        }
                    }

                }
                if(card[mxi1]==rhs.card[rhsmxi1]) {
                    if(card[mxi2]==rhs.card[rhsmxi2]) {
                        return card[lhsNot] < rhs.card[rhsNot];
                    } else return card[mxi2] < rhs.card[rhsmxi2];
                } else return card[mxi1] < rhs.card[rhsmxi1];

            } else if(lhsPos == 3) { //three_card
                int idx = findThreeCard(), rhsidx = rhs.findThreeCard();
                return card[idx] < rhs.card[rhsidx];
            } else if(lhsPos == 4) { //straight
                return card[4]<rhs.card[4];
            } else if(lhsPos == 5) { //flush
                if(card[4] == rhs.card[4]) {
                    if(card[3] == rhs.card[3]) {
                        if(card[2] == rhs.card[2]) {
                            if(card[1] == rhs.card[1]) {
                                return card[0] < rhs.card[0];
                            } else return card[1] < rhs.card[1];
                        } else return card[2] < rhs.card[2];
                    } else return card[3] < rhs.card[3];
                } else return card[4] < rhs.card[4];
            } else if(lhsPos == 6) { //full house
                //first: 3 same, second: 2 same
                pii grp = findFullHouseGroup(), rhsgrp = rhs.findFullHouseGroup();
                if(card[grp.first]==rhs.card[rhsgrp.first]) return card[grp.second] < rhs.card[rhsgrp.second];
                else return card[grp.first] < rhs.card[rhsgrp.first];
            } else if(lhsPos == 7) { //four card
                int idx = findFourCard(), rhsidx = rhs.findFourCard();
                return card[idx] < rhs.card[rhsidx];
            } else if(lhsPos == 8) { //straight_flush
                return card[4]<rhs.card[4];
            } else  return false; //unreachable code
        } else return lhsPos < rhsPos;
    }

    bool operator==(const Deck &rhs) const {
        int lhsPos = getPos(), rhsPos = rhs.getPos();
        if(lhsPos != rhsPos) return false;

        for(int i=0; i<5; i++) {
            if(card[i] != rhs.card[i]) return false;
        }
        return true;
    }

    void setPos() {
        int cnt=1;
        for(int i=1; i<5; i++) {
            if(card[i].shape[1] == card[0].shape[1]) cnt++;
        }

        if(cnt==5) { //straight_flush or flush
            cnt=1;
            for(int i=1; i<5; i++) {
                if(order[uint(card[i-1].shape[0])]+1 == order[uint(card[i].shape[0])]) {
                    cnt++;
                }
            }
            if(cnt==5) pos = 8; //straight flush
            else pos = 5; //flush;
            return;
        }

        int op=0, tc=0;
        for(int i=0; i<4; i++) {
            for(int j=i+1; j<5; j++) {
                if(card[i]==card[j]) op++;
            }
        }

        for(int i=0; i<3; i++) {
            for(int j=i+1; j<4; j++) {
                if(card[i]!=card[j]) continue;
                for(int k=j+1; j<5; j++) {
                    if(card[j]==card[k]) {
                        tc++;
                        goto BRK;
                    }
                }
            }
        }
BRK:
        if(tc!=0) {
            for(int i=0; i<2; i++) {
                for(int j=i+1; j<3; j++) {
                    if(card[i]!=card[j]) continue;
                    for(int k=j+1; k<4; k++) {
                        if(card[j]!=card[k]) continue;
                        for(int l=k+1; l<5; l++) {
                            if(card[k]==card[l]) {
                                pos = 7; //four card
                                return;
                            }
                        }
                    }
                }
            }
        }

        if(op==0 && tc==0) {
            cnt=1;
            for(int i=1; i<5; i++) {
                if(order[uint(card[i-1].shape[0])]+1 == order[uint(card[i].shape[0])]) {
                    cnt++;
                }
            }
            if(cnt==5) pos = 4; //straight
            else pos=0; //high card
            return;
        }

        if(op==1) pos = 1; //one pair
        else if(op==2) pos = 2; //two pair
        else if(tc==1) {
            if(op==4) pos = 6; //full house
            else pos = 3; //three card
        }
    }
};
void init() {
    for(int i=0; i<13; i++) {
        order[uint(order_shape[i])] = i;
    }
}
Deck black, white;
char c[3];
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    while(true) {
        for(int i=0; i<5; i++) {
            if(scanf("%s", c) == EOF) return 0;
            black.card[i].shape = string(c);
        }
        black.sort();
        black.setPos();
        for(int i=0; i<5; i++) {
            scanf("%s", c);
            white.card[i].shape = string(c);
        }
        white.sort();
        white.setPos();

        if(black == white) puts("Tie.");
        else if(black < white) puts("White wins.");
        else puts("Black wins.");
    }
    return 0;
}
