#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int ans=0, something=1234;

    //트리에서 말단 노드부터 순서대로 정렬되어있는 값이 있을 때
    //트리의 지름을 한방에 구할 수 있다. (트리 안만들어도 됨.)
    int n; scanf("%d", &n);
    vector<int> v(n), dist(n,0), parent(n);
    sort(v.begin(), v.end()); //이걸로 말단노드부터 정렬이 되었다고 치자.

    for(int i=0; i<n; i++) {
        parent[i] = something; //parent 정보를 알아서 잘 맞게 갱신
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(parent[v[i]] == v[j]) { //v[i]의 parent가 v[j]인 경우
                //i의 부모가 j가 되지만 그런 관계로 보지말고,
                //트리니까.. 그냥 이걸 쭉 펼쳐놓고 보면
                //트리의 지름은 i와 j를 지나는 길이라고 가정했을때
                //말단노드부터 i까지의 길이 + 말단노드부터 j까지의 길이 + i~j 길이 (1) 이므로
                //위와 같이 식을 쓸 수 있다.
                ans = max(ans, dist[j]+dist[i]+1);

                //만약 i쪽에서 올라온 길이 더 긴거라면,
                //j가 i의 부모에 해당되는거니까
                //1만큼 더해준 값으로 j를 갱신하고,
                //그게 아닌 경우는 i가 부모인 셈이니까
                //j를 그대로 놔둔다.
                dist[j] = max(dist[j], dist[i]+1);
                break; //부모 하나만 처리하고 바로 break~!!
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}


//근데, 위와 같이 이렇게 무식한 방법 말고 (반복문 저게 뭥미)
//parent[]를 O(N)으로 구해두면 다시 O(N)시간 만큼만 투자해서
//트리의 지름을 구할 수 있다.
//dfs로 하는 경우엔 O(E) (간선의 수) 만큼 걸리는데... 이걸 2번도니까
//어차피 O(2N)... 같군.
//아무튼 이 코드가 간결해서 좋다.
//이와 관련된 문제는 /Users/lian/allCode/jongmanbook/fortress-1.cpp 을 참고하면 된다.
