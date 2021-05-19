#include <stdio.h>
#include <queue>
using namespace std;
struct Info{
    int cnt, z, k;
    Info(int a, int b, int c) {
        cnt = a; z=b; k=c;
    }
    bool operator<(const Info &rhs) const {
        return cnt > rhs.cnt;
    }
};
priority_queue<Info> mnh;
char a[50][5][8];
int main() {
    int n, cnt;
    scanf("%d", &n);
    for(int k=0; k<n; k++) {
        for(int i=0; i<5; i++) {
            scanf("%s", a[k][i]);
        }
    }
    for(int z=0; z<n-1; z++) {
        for(int k=z+1; k<n; k++) {
            cnt=0;
            for(int i=0; i<5; i++) {
                for(int j=0; j<7; j++) {
                    if(a[z][i][j] != a[k][i][j]) cnt++;
                }
            }
            mnh.push(Info(cnt, z, k));
        }
    }
    int a, b;
    if(mnh.top().z > mnh.top().k) {
        a=mnh.top().z+1;
        b=mnh.top().k+1;
    } else {
        a=mnh.top().k+1;
        b=mnh.top().z+1;
    }
    printf("%d %d", b, a);
}
