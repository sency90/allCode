#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

int t, n, k;
int i, j;
int w;
int cost[1001];
bool isDept[1001];
int costFromCurToW[1001];
queue<int> q[100001];

void clear( queue<int> &q )
{
    queue<int> empty;
    swap( q, empty );
}

int calc( int x ) {
    int y = 0;
    int tempCost, tempRet;
    bool everEntered = false;

    //base case
    if( x == w ) {
        //clear(q[x]);
        return cost[w];
    }

    //recursive part
    while(!q[x].empty()) {
        everEntered = true;

        y = q[x].front(); q[x].pop();

        if(costFromCurToW[y] < 0) {
            tempRet = calc(y);
        }
        else {
            tempRet = costFromCurToW[y];
        }

        if(tempRet < 0) {
            tempCost = -1;
        }
        else {
            tempCost = cost[x] + tempRet;
        }

        if(costFromCurToW[x] < tempCost) {
            costFromCurToW[x] = tempCost;
        }
    }

    //clear(q[x]);
    if(everEntered) {
        return costFromCurToW[x];
    } else {
        return -1;
    }
}

int main() {
    int x, y;
    scanf("%d", &t);
    for(j=0; j<t; j++) {
        memset(cost, 0, sizeof(cost));
        memset(isDept, true, sizeof(isDept));
        memset(costFromCurToW, -1, sizeof(costFromCurToW));
        scanf("%d", &n);
        scanf("%d", &k);

        for(i=1; i<n+1; i++) {
            scanf("%d", &cost[i]);
        }
        for(i=1; i<k+1; i++) {
            scanf("%d %d", &x, &y);
            isDept[y] = false;
            q[x].push(y);
        }

        scanf("%d", &w);
        costFromCurToW[w] = cost[w];

        for(i=1; i<n+1; i++) {
            if(isDept[i]) {
                q[0].push(i);
            }
        }
        printf("%d\n", calc(0));
    }
    return 0;
}
