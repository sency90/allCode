#include <stdio.h>
#include <algorithm>
#include <cstring>
#define mk make_pair
using namespace std;
typedef pair<int, int> pi;
int v[11][11];
pi where[11], s[11][11];

int main() {
    memset(v, -1, sizeof(v));
    int _n=1, n;
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            v[i][j]=_n++;
        }
    }
    v[4][2]=0;

    for(int k=0; k<=9; k++) {
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                if(v[i][j] == k) where[k] = mk(i,j);
            }
        }
    }

    for(int i=0; i<=9; i++) {
        for(int j=0; j<=9; j++) {
            s[i][j] = mk(where[i].first - where[j].first, where[i].second - where[j].second);
        }
    }


    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%1d", &num[i]);
    }

    for(int k=0; k<=9; k++) {
        if(k != num[0]) {
            pi pos = where[k];
            for(int i=0; i<n-1; i++) {
                pos.first += s[num]
            }
        }
    }
    return 0;
}
