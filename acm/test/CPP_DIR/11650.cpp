#include <stdio.h>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
struct Coord{
    int x, y;
    bool operator>(const Coord& rhs) const {
        if(x > rhs.x) return true;
        else if(x == rhs.x) {
            if(y > rhs.y) return true;
            else return false;
        }
        else return false;
    }
};

priority_queue<Coord, vector<Coord>, greater<Coord> > minheap;
int main() {
    Coord co;
    int n; scanf("%d", &n);
    while(n--) {
        scanf("%d %d",&co.x,&co.y);
        minheap.push(co);
    }
    while(!minheap.empty()) {
        co = minheap.top();
        printf("%d %d\n", co.x, co.y);
        minheap.pop();
    }
    return 0;
}
