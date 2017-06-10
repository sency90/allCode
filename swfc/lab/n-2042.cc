#include <iostream>
#include <cstdio>
using namespace std;
int v[9][9], row[9], col[9], room[3][3];
int idx=0;
struct Pos{
    int r,c;
    Pos(){}
    Pos(int r, int c):r(r),c(c){}
}pos[81];
bool check(int n, int i) {
    int r = pos[n].r, c = pos[n].c;
    if (((row[r]>>i)&1) == 1) return false;
    if (((col[c]>>i)&1) == 1) return false;
    if (((room[r/3][c/3]>>i)&1) == 1) return false;
    return true;
}
bool dfs(int n) {
    int r=pos[n].r, c=pos[n].c;
    if(n==idx) return true;

    for(int i=1; i<=9; i++) {
        if(check(n,i)) {
            v[r][c] = i;
            row[r]|=(1<<i);
            col[c]|=(1<<i);
            room[r/3][c/3]|=(1<<i);

            if(dfs(n+1)) return true;

            v[r][c] = 0;
            row[r]^=(1<<i);
            col[c]^=(1<<i);
            room[r/3][c/3]^=(1<<i);
        }
    }
    return false;
}
int main() {
    //freopen("input.txt", "r", stdin);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d", &v[i][j]);
            //printf("%d,%d:: %d\n", i,j,3*(i/3)+(j/3));
            if(v[i][j]==0) pos[idx++]=Pos(i,j);
            else {
                row[i]|=(1<<v[i][j]);
                col[j]|=(1<<v[i][j]);
                room[i/3][j/3]|=(1<<v[i][j]);
            }
        }
    }

    dfs(0);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", v[i][j]);
        } puts("");
    }
}
