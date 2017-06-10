#include <iostream>
#include <string>
using namespace std;
int n,k;
string s;
int d[26][100001];
inline int calc(char x, char y) {
    int ret = (y-'a')-(x-'a');
    ret=(ret<0)?-ret:ret;
    return min(26-ret,ret);
}
bool judge(int x) {
    for(int i=0; i<26; i++) {
        for(int j=x; j<=n; j++) {
            if(d[i][j]-d[i][j-x]<=k) return true;
        }
    }
    return false;
}
int main() {
    freopen("input2.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k>>s;
    for(int i=0; i<26; i++) {
        char base='a'+i;
        for(int j=0; j<n; j++) {
            d[i][j+1]=d[i][j]+calc(s[j],base);
        }
    }

    int lo=0, hi=s.size();
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(judge(mid)) lo=mid+1;
        else hi=mid-1;
    }
    printf("%d\n",lo-1);
    return 0;
}
