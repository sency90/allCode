#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

int w;
int cost[1002];
int costFromCurToW[1002];
queue<int> q[100002];

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
    
    if(everEntered) {
        return costFromCurToW[x];
    } else {
        return -1;
    }
}

int main() {
    int x, y;
    int t, n, k;
    bool isStartNode[1002];
    
    scanf("%d", &t);
    for(int j=0; j<t; j++) {
        scanf("%d", &n);
        scanf("%d", &k);
        memset(cost, 0, (n+2)*sizeof(int));
        memset(isStartNode, true, (n+2)*sizeof(bool));
        memset(costFromCurToW, -1, (n+2)*sizeof(int));
        
        for(int i=1; i<n+1; i++) {
            scanf("%d", &cost[i]);
        }
        for(int i=1; i<k+1; i++) {
            scanf("%d %d", &x, &y);
            isStartNode[y] = false;
            q[x].push(y);
        }
        
        scanf("%d", &w);
        costFromCurToW[w] = cost[w];
        
        for(int i=1; i<n+1; i++) {
            if(isStartNode[i]) {
                q[0].push(i);
            }
        }
        printf("%d\n", calc(0));
        for(int ii=0; ii<k+1; ii++) {
            queue<int> empty;
            swap( q[ii], empty );
        }
    }
    return 0;
}