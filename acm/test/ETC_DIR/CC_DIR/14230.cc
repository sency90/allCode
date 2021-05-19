#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
struct Info{
    vector<pii> co;
    pii vec;
    Info():vec(0,0){}
    Info(int x, int y):vec(x,y){}
    int operator*(const Info &rhs) {
        return vec.first*rhs.vec.first+vec.second*rhs.vec.second;
    }

    bool operator<(const Info &rhs) {
        if(vec.first == rhs.vec.first) return vec.second < rhs.vec.second;
        else return vec.first < rhs.vec.first;
    }
    bool operator==(const Info &rhs) {
        return (vec.first == rhs.vec.first) && (vec.second == rhs.vec.second);
    }
};
bool operator==(const pii &lhs, const pii &rhs) {
    return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}
vector<Info> v;
vector<pii> co;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,y; scanf("%d%d", &x,&y);
        co.emplace_back(pii(x,y));
    }
    //일단 중복되는 좌표가 없다고 가정하고 문제를 풀어보자.
    //vector<pii> v;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(i==j) continue;
            else {
                Info info(co[i].first-co[j].first, co[i].second-co[j].second);
                info.co.emplace_back(co[i]);
                info.co.emplace_back(co[j]);
                v.emplace_back(info);
                //v.emplace_back(pii(co[i].first-co[j].first, co[i].second-co[j].second));
                //v.emplace_back(Info(co[i].first-co[j].first, co[i].second-co[j].second));
            }
        }
    }
    int mx=0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(i==j) continue;
            if(v[i]*v[j] == 0) {
                vector<pii> tmp;
                for(int k=0; k<v[i].co.size(); k++) {
                    tmp.emplace_back(v[i].co[k]);
                }
                for(int k=0; k<v[j].co.size(); k++) {
                    tmp.emplace_back(v[i].co[k]);
                }
                sort(tmp.begin(), tmp.end());
                tmp.erase(tmp.unique(tmp.begin(), tmp.end()), tmp.end());
                tmp.erase(tmp.begin(), tmp.end());
                //tmp.erase(tmp.unique(tmp.begin(), tmp.end()), tmp.end());
                max(mx,int(tmp.size()));
            }
        }
    }
    printf("%d\n", mx);
    return 0;
}
