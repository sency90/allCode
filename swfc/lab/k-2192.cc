#include <stdio.h>
int n,m, dice[6]; 
void dfs(int x) {
    if(x>n) {
        for(int i=1; i<=n; i++) {
            printf("%d ", dice[i]);
        } puts("");
        return;
    }
    for(int i=1; i<=6; i++) {
        dice[x]=i;
        dfs(x+1);
    }
}
void dfs2(int x, int s) {
    if(x>n) {
        for(int i=1; i<=n; i++) {
            printf("%d ", dice[i]);
        } puts("");
        return;
    }
    for(int i=s; i<=6; i++) {
        dice[x]=i;
        dfs2(x+1, i);
    }
}
void dfs3(int x, bool *chk) {
    if(x>n) {
        for(int i=1; i<=n; i++) {
            printf("%d ", dice[i]);
        } puts("");
        return;
    }
    for(int i=1; i<=6; i++) {
        if(!chk[i]) {
            chk[i]=true;
            dice[x]=i;
            dfs3(x+1,chk);
            chk[i]=false;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    bool chk[7];
    for(int i=0; i<7; i++) chk[i]=false;
    scanf("%d%d", &n,&m);
    if(m==1) dfs(1);
    else if(m==2) dfs2(1,1);
    else dfs3(1,chk);
    return 0;
}
