#include <cstdio>
using namespace std;
int arr[1001];
bool visited[1001];
int f(int x) {
    if(x==1) return 1;
    else if(x==2) return 2;

    if(visited[x] == true) return arr[x];
    else visited[x]=true;

    arr[x] = (f(x-1)+f(x-2))%10007;
    return arr[x];
}
int main() {
    int n; scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
