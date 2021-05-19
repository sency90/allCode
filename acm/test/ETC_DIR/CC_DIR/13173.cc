#include <cstdio>
#include <cstring>
using namespace std;
int P,Q,N,K;
int A[102][102], B[102][102]; // A/B
inline double ABS(double x, double y) { return x*y<0?-(x/y):x/y; }
void SWAP(int x, int y) {
    int tmp;
    for(int i=0; i<=N; i++) {
        tmp = A[x][i];
        A[x][i] = A[y][i];
        A[y][i] = tmp;
        tmp = B[x][i];
        B[x][i] = B[y][i];
        B[y][i] = tmp;
    }
}
int main() {
    scanf("%d%d%d%d",&P,&Q,&N,&K);
    for(int i=0; i<=N; i++) {
        if(i-2>=0) A[i][i-1] = -P+Q;
        A[i][i] = P;
        if(i+2<=N) A[i][i+1] = -Q;
    }
    A[N+1][0] = A[N+1][N] = A[N+1][N+1] = 1;
    for(int i=0; i<=N+1; i++) {
        for(int j=0; j<=N+1; j++) {
            B[i][j] = 1;
        }
    }

    for(int i=0; i<=N+1; i++) { for(int j=0; j<=N+1; j++) { printf("%d ", A[i][j]); } puts(""); } puts("");

    for(int i=0; i<=N+1; i++) {

        int mxrow=i;
        for(int row=i+1; row<=N+1; row++) {
            if(ABS(A[row][i],B[row][i]) > ABS(A[mxrow][i],B[mxrow][i])) mxrow=row;
        }
        if(mxrow!=i) SWAP(i, mxrow);
        puts("before");
        for(int i=0; i<=N+1; i++) { for(int j=0; j<=N+1; j++) { printf("%d ", A[i][j]); } puts(""); } puts("");


        if(A[i][i]==0) continue;
        for(int icol=i+1; icol<=N+1; icol++) {
            B[i][icol] *= A[i][i];
            A[i][icol] *= B[i][i];
            //A[i][icol] /= A[i][i];
        }
        for(int row=0; row<=N+1; row++) {
            if(row == i) continue;
            if(A[row][i]==0) continue;
            for(int col=i+1; col<=N+1; col++) {
                A[row][col] -= A[row][i] * A[i][col];
            }
            A[row][i]=0;
        }
        A[i][i] = 1;

        puts("after");
        for(int i=0; i<=N+1; i++) { for(int j=0; j<=N+1; j++) { printf("%d ", A[i][j]); } puts(""); } puts("");
    }

    printf("%lf %lf\n", (double)A[0][N+1]/B[0][N+1], (double)A[N+1][N+1]/B[N+1][N+1]);
    return 0;
}
