#include <iostream>
#include <cstring>
using namespace std;
bool fr[10][10], taken[10];
int t,n,m,x,y;
int coupling() {
    int first = -1;
    for(int i=0; i<n; i++) {
        if(!taken[i]) {
            first = i;
            break;
        }
    }
    if(first<0) return 1;

    int ret = 0;
    for(int i=first+1; i<n; i++ ){
        if(!taken[i]&&fr[first][i]) {
            taken[first]=taken[i]=true;
            ret += coupling();
            taken[first]=taken[i]=false;
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    freopen("/Users/lian/allCode/xcode_ws/acm/acm/input.txt", "r", stdin);
    cin >> t;
    while(t--) {
        memset(fr, false, sizeof(fr));
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            cin >> x >> y;
            fr[x][y]=fr[y][x]=true;
        }

        memset(taken, false, sizeof(taken));
        int ret = 0;
        ret += coupling();
        cout << ret << "\n";
    }
    return 0;
}
