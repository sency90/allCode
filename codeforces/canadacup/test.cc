#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int,int> pii;
namespace plzrun {
    template <typename T> class greater{
    public:
        T x;
        bool operator()(const greater<T>& lhs, const greater<T>& rhs) const {
            return lhs.x<rhs.x;
        }
        bool operator<(const greater& rhs) const {
            return std::less<T>(x,rhs);
        }
    };
};
vector<plzrun::greater<int>> a;
priority_queue<pii,std::vector<pii>,plzrun::greater<pii>> h;
int main() {
    sort(a.begin(), a.end(), plzrun::greater<int>());
    h.push({1,2});
    h.push({2,3});
    h.push({0,1});
    h.push({1,3});
    while(!h.empty()) {
        printf("%d %d\n",h.top().first, h.top().second);
        h.pop();
    }
    return 0;
}
