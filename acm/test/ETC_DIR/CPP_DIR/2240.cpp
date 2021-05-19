#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
short v[1000];
short d[31][1000][2];
//d[m][i][a]
//a=1이면 v[i]를 포함한 경우, a=0이면 v[i]를 포함하지 않은 경우
//m은 v[0]부터 v[i]까지 고려했을때 m번 바꿨음을 의미
//v[i]는 바꿀수 있는 경우가 나오기 전까지 자두의 개수를 의미
//즉, 2 1 1 1 2 2 1 1 1 1 2 1 이라는 입력이 들어왔다면,
//v[0]=1, v[1]=3, v[2]=2, v[3]=4, v[4]=1, v[5]=1이 된다.
short f(int m, int i, int a) {
    if(m<0 || i<0) return 0;
    if(d[m][i][a] > 0) return d[m][i][a];
    return d[m][i][a] = max(f(m-1, i-1, a), f(m, i-1, 1-a)) + (a==1? v[i]:0);
}
int main() {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    short t, w, k=0, d, pd;
    scanf("%hd %hd", &t, &w);
    scanf("%hd", &d);
    pd = d;
    v[k]++;
    for(int i=1; i<t; i++) {
        scanf("%hd", &d);
        if(pd == d) {
            v[k]++;
        } else {
            v[++k]++;
            pd = d;
        }
    }
    short tmp, mx = f(w, k, 0);
    if(mx < (tmp = f(w, k, 1))) mx = tmp;
    printf("%hd", mx);
    return 0;
}
