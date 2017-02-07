#include <cstdio>
using namespace std;
bool chk[100001];
int main() {
    int n,m,z;
    scanf("%d%d%d",&n,&m,&z);
    for(int i=1; i*n<=z; i++) {
        chk[i*n]=true;
    }
    int cnt=0;
    for(int i=1; i*m<=z; i++) {
        if(chk[i*m]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
