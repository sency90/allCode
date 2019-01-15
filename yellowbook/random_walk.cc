#include <cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
char mp[11][12];
double mat[101][122];
template <class T> void swap(T *a, T *b, int N) {
    T tmp;
    for(int i=0; i<N; i++) {
        tmp=a[i]; a[i]=b[i]; b[i]=tmp;
    }
}
double ABS(double x) { return x<0?-x:x; }
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", mp[i]);
    }

    //연립방정식을 만든다.
    const int C = n*m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int row = i*n+j;
            if(row == C-1) continue;
            if(mp[i][j]=='#') {
                //mat[row][i*n+j] = 0;
                //mat[row][C] = 0;
            } else {
                bool a,b,c,d; a=b=c=d=false;
                if(i>0) {
                    double &up = mat[row][(i-1)*n+j];
                    if(mp[i-1][j]=='#') up = 0;
                    else up = -1, a=true;
                }
                if(i+1<n) {
                    double &down = mat[row][(i+1)*n+j];
                    if(mp[i+1][j]=='#') down = 0;
                    else down = -1, b=true;
                }
                if(j>0) {
                    double &left = mat[row][i*n+j-1];
                    if(mp[i][j-1]=='#') left = 0;
                    else left = -1, c=true;
                }
                if(j+1<m) {
                    double &right = mat[row][i*n+j+1];
                    if(mp[i][j+1]=='#') right = 0;
                    else right = -1, d=true;
                }
                mat[row][C-1] = 0;
                if((a|b|c|d) == false) {
                    mat[row][i*n+j] = 0;
                    mat[row][C] = 0;
                }
                else {
                    mat[row][i*n+j] = 4;
                    mat[row][C] = 4;
                }
            }
        }
    }
    for(int i=0; i<C; i++) {
        for(int j=0; j<=C; j++) {
            printf("%lf ", mat[i][j]);
        } puts("");
    }

    for(int i=0; i<C; i++) {
        int pivot = i;
        for(int row=i; row<C; row++) {
            if(ABS(mat[row][i])>ABS(mat[pivot][i])) pivot = row;
        }

        swap(mat[i], mat[pivot], C+1);

        if(mat[i][i]==0) continue;
        else {
            for(int col=i+1; col<=C; col++) mat[i][col]/=mat[i][i];
            for(int row=0; row<C; row++) {
                if(row == i) continue;
                for(int col=i+1; col<=C; col++) {
                    mat[row][col]-=mat[row][i]*mat[i][col];
                }
            }
        }

        printf("\n[%d]\n",i);
        for(int i=0; i<C; i++) {
            for(int j=0; j<=C; j++) {
                printf("%.2lf ", mat[i][j]);
            }
            puts("");
        }
    }
    printf("%lf", mat[0][C]);
    return 0;
}
