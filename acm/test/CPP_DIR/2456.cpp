#include <stdio.h>
#include <algorithm>
using namespace std;
struct Student {
    int sumscr=0, score[3]={0,0,0}, idx;

    bool operator==(const Student& rhs) const {
        if(sumscr == rhs.sumscr) {
            int i=2;
            for(; i>=0; i--) {
                if(score[i] != rhs.score[i]) break;
            }
            if(i == -1) return true;
        }
        return false;
    }

    bool operator<(const Student& rhs) const {
        if(sumscr == rhs.sumscr) {
            if(score[2] == rhs.score[2]) {
                if(score[1] == rhs.score[1]) {
                    if(score[0] == rhs.score[0]) {
                        return false;
                    } else if(score[0] > rhs.score[0]) return true;
                } else if(score[1] > rhs.score[1]) return true;
            } else if(score[2] > rhs.score[2]) return true;
        } else if(sumscr > rhs.sumscr) return true;
        return false;
    }
}s[3];

int main() {
    int n, d; scanf("%d", &n);
    for(int i=0; i<3; i++) s[i].idx = i+1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &d);
            s[j].sumscr += d;
            s[j].score[d-1]++;
        }
    }

    sort(s, s+3);
    if(s[0]==s[1]) {
        printf("0 %d\n", s[0].sumscr);
    } else {
        printf("%d %d\n", s[0].idx, s[0].sumscr);
    }
    return 0;
}
