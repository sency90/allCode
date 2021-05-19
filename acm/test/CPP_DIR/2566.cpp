#include <stdio.h>
#include <queue>
using namespace std;
struct Room{
    int v, x, y;
    Room(int vv, int xx, int yy) {
        v=vv; x=xx; y=yy;
    }
    bool operator<(const Room &rhs) const{
        return v < rhs.v;
    }
};
priority_queue<Room> mxh;
int main() {
    int d;
    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            scanf("%d", &d);
            mxh.push(Room(d,i,j));
        }
    }
    printf("%d\n%d %d", mxh.top().v, mxh.top().x, mxh.top().y);
    return 0;
}
