#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
bool visited[10001];
class node {
    public:
        int value;
        int count; // s부터 해당 노드까지 거리
        node() {
            count = 0;
        }
};

bool isPrime(int N) {
    if (N <= 1) return false;
    for (int i = 2; i*i<=N; i++) {
        if (N%i == 0) {
            //        cout << i << endl;
            return false;
        }
    }
    return true;
}

void toArr(int value, int* arr) {
    for (int i = 0; i < 4; i++) {
        arr[i] = value / (int)pow(10, 3 - i);
        value = value % (int)pow(10, 3 - i);
    }
}

int toNum(int* arr) {
    int n=0;
    for (int i = 0; i < 4; i++) {
        n += arr[i] * pow(10, 3 - i);
    }
    return n;
}
int bfs(int start, int end) {
    int arr[4];
    node n;
    n.value = start;
    memset(visited, false, sizeof(visited));
    visited[n.value] = true;
    int value;
    queue<node> q;
    q.push(n);
    while (!q.empty()) {
        node p = q.front(); q.pop();
        if (p.value == end) return p.count;
        for (int i = 0; i < 4; i++) {
            toArr(p.value, arr);
            for (int j = 0; j <= 9; j++) {
                arr[i] = j;
                value = toNum(arr);
                if (value >= 1000 && isPrime(value) && visited[value]==false) {
                    n.value = value;
                    n.count = p.count + 1;
                    visited[value] = true;
                    q.push(n);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    int start, end;
    int count;
    for (int i = 0; i < T; i++) {
        cin >> start >> end;
        int ans = bfs(start, end);
        if(ans!=-1) cout << ans;
        else cout << "Impossible" <<"\n";
    }
    return 0;
}
