//일단 이 문제는 영어 해석부터가 잘 이해가 안됐었는데...
//이 문제는 그니까.. 음...
//분자간의 공유결합이 주어지면 여기서 방향을 결정하고자 하는 것인데,
//방향이 한쪽으로 통할 수 있으면 불안정한 상태가 된다고 한다.
//그래서 이걸 최대한 안정적인 상태로 만들고 싶다는데,
//그럼 결국 1->2<-3->4 이런식이 되고 싶다는 거다..
//그러니까 1->2->3<-4 같은 경우는 1->2->3이 한쪽 방향으로 쭉 통하게 되니까 안되는 거다.
//그러면 모든 노드를 red와 black으로 색칠한다고 생각하자.
//이 문제는 에지의 개수가 노드의개수-1이므로 트리이다.
//그러므로 모든 노드를 bfs로 탐색하면서 하나를 red로 칠하면 이웃은 black으로 칠할 수 있다.
//당연히 그 반대도 가능하다.
//그렇게 색칠을 번갈아가면서 전부 다 했으면,
//red->black 경로는 1이라 출력하고 black->red 경로는 0이라 출력하자.
//당연히 그 반대도 답이 될 수 있다.
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v[100001];
queue<int> q;
int s[100001], ans[100001];
int main() {
    int n, y;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d", &s[i], &y);
        v[s[i]].push_back(y);
        v[y].push_back(s[i]);
    }

    memset(ans, -1, sizeof(ans));
    ans[1] = 1;
    q.push(1);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i=0; i<v[x].size(); i++) {
            if(ans[v[x][i]] != -1) continue;
            ans[v[x][i]] = 1-ans[x];
            q.push(v[x][i]);
        }
    }

    for(int i=1; i<n; i++) {
        printf("%d\n", ans[s[i]]);
    }
    return 0;
}
