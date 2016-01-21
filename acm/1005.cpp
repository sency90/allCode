#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int t, n, k;
int i, j;
int x, y, w;
int cost[1001];
bool isDept[1001];
int fromNODEtoW[1001];
queue<int> q[100001];
//queue<int> &q;

void clear( queue<int> &q )
{
    queue<int> empty;
    swap( q, empty );
}

int calc( int dept ) {
    int dest, tempCost;
    bool everEntered = false;
    
    while(!q[dept].empty()) {
        everEntered = true;
        dest = q[dept].front();
        q[dept].pop();
        
        if(-1 == fromNODEtoW[dest]) {
            fromNODEtoW[dest] = calc(dest);
        }
        
        tempCost = cost[dept] + fromNODEtoW[dest];
        
        if(fromNODEtoW[dept] < tempCost || -1 == fromNODEtoW[dept]) {
            fromNODEtoW[dept] = tempCost;
        }
    }
    
    if(everEntered) {
        clear(q[dept]);
        return fromNODEtoW[dept];
    }
    else { //base case
        clear(q[w]);
        fromNODEtoW[w] = cost[w];
        return fromNODEtoW[w];
    }
}

int main() {
    scanf("%d", &t);
    while(t--) {
        
        //memset(cost, 0, sizeof(cost));
        //memset(isDept, true, sizeof(isDept));
        //memset(fromNODEtoW, -1, sizeof(fromNODEtoW));
        scanf("%d", &n);
        memset(cost, 0, (n+1)*sizeof(cost[0]));
        memset(isDept, true, (n+1)*sizeof(bool));
        memset(fromNODEtoW, -1, (n+1)*sizeof(fromNODEtoW[0]));
        
        scanf("%d", &k);
        
        for(i=1; i<n+1; i++) {
            scanf("%d", &cost[i]);
        }
        for(i=1; i<k+1; i++) {
            scanf("%d %d", &x, &y);
            isDept[y] = false;
            q[x].push(y);
        }
        for(i=1; i<n+1; i++) {
            if(isDept[i]) {
                q[0].push(i);
            }
        }
        
        scanf("%d", &w);
        printf("%d\n", calc(0));
    }
    return 0;
}