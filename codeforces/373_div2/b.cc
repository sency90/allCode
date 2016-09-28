#include <string>
#include <iostream>
using namespace std;
pair<int,int> ans[2];
int mx[2];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,cmp1,cmp2;
    char c[]={'r','b'};
    int n;
    cin>> n;
    cin >> s;

    for(int i=0, j=0; i<n; i++, j^=1) {
        if(s[i]!=c[j]) {
            if(s[i]=='r') ans[0].first++;
            else ans[0].second++;
        }
        if(s[i]!=c[j^1]) {
            if(s[i]=='r') ans[1].first++;
            else ans[1].second++;
        }
    }
    mx[0]=max(ans[0].first, ans[0].second);
    mx[1]=max(ans[1].first, ans[1].second);
    printf("%d\n", mx[0]<mx[1]?mx[0]:mx[1]);
    return 0;
}
