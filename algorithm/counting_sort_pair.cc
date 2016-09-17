#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<pair<int,int> >  v;
int cnt[100], sortedIdx[100], oriIdx[100];
int main() {
    int n;
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);

    //input
    for(int i=0; i<n; i++) {
        cin >> v[i].first >>v[i].second;
    }

    //second에 대해서 counting sort
    for(int i=0; i<n; i++) cnt[v[i].second]++;
    for(int i=1; i<=10; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) oriIdx[--cnt[v[i].second]] = i;

    //second가 정렬된 상태에서 first를 counting sort로 정렬하기.
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++) cnt[v[i].first]++;
    for(int i=1; i<=10; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) sortedIdx[--cnt[v[oriIdx[i]].first]] = oriIdx[i];

    //정렬된 결과 출력
    for(int i=0; i<n; i++) {
        cout << v[sortedIdx[i]].first << ", " << v[sortedIdx[i]].second << "\n";
    }
    return 0;
}
