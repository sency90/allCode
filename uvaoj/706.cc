#include <stdio.h>
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
struct Block{
    int dir[8];
    Block(){} Block(int a, int b, int c, int d){ dir[0]=a; dir[1]=b; dir[2]=c; dir[3]=d; }
};


char num[10];
Block top[10], bot[10];
char ans[24][13];
char realAns[240][130];
int main() {
    top[0]=Block(1,0,1,1); bot[0]=Block(1,1,1,0);
    top[1]=Block(1,0,0,0); bot[1]=Block(1,0,0,0);
    top[2]=Block(1,1,0,1); bot[2]=Block(0,1,1,1);
    top[3]=Block(1,1,0,1); bot[3]=Block(1,1,0,1);
    top[4]=Block(1,1,1,0); bot[4]=Block(1,0,0,1);
    top[5]=Block(0,1,1,1); bot[5]=Block(1,1,0,1);
    top[6]=Block(0,1,1,1); bot[6]=Block(1,1,1,1);
    top[7]=Block(1,0,0,1); bot[7]=Block(1,0,0,0);
    top[8]=Block(1,1,1,1); bot[8]=Block(1,1,1,1);
    top[9]=Block(1,1,1,1); bot[9]=Block(1,1,0,1);

    while(true) {
        int s; scanf("%d %s", &s, num);
        if(s==0) break;

        int N=2*s+3, M=s+2, mid=s+1;

        int cnt=0;
        for(cnt=0; num[cnt]; cnt++);
        for(int i=0; i<cnt; i++) num[i]-='0';

        int py=0;
        for(int z=0; z<cnt; z++) {
            for(int i=0; i<N; i++) for(int j=0; j<M; j++) ans[i][j] = ' ';

            if(py!=0) {
                for(int i=0; i<N; i++) realAns[i][py]=' ';
                py++;
            }

            for(int i=1; i<N-1; i++) {
                if(i==1)        { if(top[num[z]].dir[3]) for(int j=1; j<M-1; j++) ans[i-1][j]='-'; }
                if(i==mid-1)    { if(top[num[z]].dir[1]) for(int j=1; j<M-1; j++) ans[i+1][j]='-'; }
                if(i==N-2)      { if(bot[num[z]].dir[1]) for(int j=1; j<M-1; j++) ans[i+1][j]='-'; }

                if(i<mid) {
                    if(top[num[z]].dir[0]) ans[i][M-1]='|';
                    if(top[num[z]].dir[2]) ans[i][0]='|';
                } else if(i>mid) {
                    if(bot[num[z]].dir[0]) ans[i][M-1]='|';
                    if(bot[num[z]].dir[2]) ans[i][0]='|';
                }
            }

            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) realAns[i][j+py] = ans[i][j];
                realAns[i][M+py]=0;
            }

            py+=M;
        }
        for(int i=0; i<N; i++) printf("%s\n", realAns[i]);
        puts("");
    }
    return 0;
}
