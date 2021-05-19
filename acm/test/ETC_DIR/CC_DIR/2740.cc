#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> mat;
mat A,B;
mat operator*(mat &A, mat &B) {
    int n,m,l;
    n=A.size(); m=B.size(); l=B[0].size();
    mat ret(n, vector<int>(l,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<l; j++) {
            for(int k=0; k<m; k++) {
                ret[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return ret;
}
int main() {
    int n,m,k;
    scanf("%d%d",&n,&m);
    A.resize(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d%d",&m,&k);
    B.resize(m, vector<int>(k));
    for(int i=0; i<m; i++) {
        for(int j=0; j<k; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    mat res = A*B;
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            printf("%d ", res[i][j]);
        } puts("");
    }
    return 0;
}
