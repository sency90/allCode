#if 0 //중복있는 완탐
#include <bits/stdc++.h>
using namespace std;
vector<int> v = {1,3,2,2,3,2};
bool chk[7];
void dfs(vector<int> & g) {
    if(g.size() == v.size()) {
        for(int i=0; i<g.size(); i++) {
            printf("%d ", g[i]);
        }
        puts("");
        return;
    }

    for(int i=0; i<v.size(); i++) {
        if(chk[i]) continue;
        chk[i] = true;
        g.push_back(v[i]);
        dfs(g);
        g.pop_back();
        chk[i] = false;
    }
}
int main() {
    sort(v.begin(), v.end());
    vector<int> g;
    dfs(g);
    return 0;
}
#endif

#if 0 //중복없는 완탐
#include <bits/stdc++.h>
using namespace std;
vector<int> v = {1,3,2,2,3,2};
bool chk[7];
void dfs(vector<int> & g) {
    if(g.size() == v.size()) {
        for(int i=0; i<g.size(); i++) {
            printf("%d ", g[i]);
        }
        puts("");
        return;
    }

    for(int i=0; i<v.size(); i++) {
        if(chk[i]) continue;
        if(i>0 && v[i-1]==v[i] && !chk[i-1]) continue; //이 부분만 추가됨.
        chk[i] = true;
        g.push_back(v[i]);
        dfs(g);
        g.pop_back();
        chk[i] = false;
    }
}
int main() {
    sort(v.begin(), v.end());
    vector<int> g;
    dfs(g);
    return 0;
}
#endif

#if 1 //중복없는 완탐 (개수 세기)
#include <bits/stdc++.h>
using namespace std;
vector<int> v = {1,2,7,3,8,1,7,3,9,1,2,0,0,5};
//bool chk[16];
int cnt;
inline bool chk(int bit, int i) {
    return (bit>>i)&1;
}
void dfs(vector<int> & g, int chkbit) {
    if(g.size() == v.size()) {
        cnt++;
        return;
    }

    for(int i=0; i<v.size(); i++) {
        if(chk(chkbit,i)) continue;
        if(i>0 && v[i-1]==v[i] && !chk(chkbit,i-1)) continue; //이 부분만 추가됨.
        chkbit^=(1<<i);
        g.push_back(v[i]);
        dfs(g,chkbit);
        g.pop_back();
        chkbit^=(1<<i);
    }
}
int main() {
    sort(v.begin(), v.end());
    vector<int> g;
    dfs(g,0);
    printf("%d\n", cnt);
    return 0;
}
//근데 이걸 dp로 할 순 없다.
//이 완탐은 중복되는 부분문제가 하나도 없다.
//dfs()의 인자로 들어가는 g값이 딱 1번만 호출되기 때문이다.
//그런데 짐바브웨(ZIMBABWE) 문제는 m의 배수라는 조건을 부여해서
//중복되는 부분문제를 만들어줬다.
//오히려 이 조건 때문에 dp가 가능해진 것이다.
#endif