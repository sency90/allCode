#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
string s;
deque<int> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s == "push") {
            int x; cin >> x;
            q.push_back(x);
        }
        else if(s == "front") {
            if(q.empty()) puts("-1");
            else printf("%d\n", q.front());
        }
        else if(s == "back") {
            if(q.empty()) puts("-1");
            else printf("%d\n", q.back());
        }
        else if(s == "size") {
            printf("%lu\n", q.size());
        }
        else if(s == "empty") {
            if(q.empty()) puts("1");
            else puts("0");
        }
        else {
            if(q.empty()) puts("-1");
            else {
                printf("%d\n", q.front());
                q.pop_front();
            }
        }
    }
    return 0;
}
