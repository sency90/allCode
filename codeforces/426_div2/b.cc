#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char s[1000003];
int chks[26], chke[26], sum[1000003];
int main() {
    int n,k; scanf("%d%d",&n,&k);
    scanf("%s", s);
    memset(chks,-1,sizeof(chks));
    memset(chke,-1,sizeof(chke));
    for(int i=0; s[i]; i++) {
        int idx=s[i]-'A';
        if(chks[idx]<0) chks[idx]=i;
        chke[idx]=i+1;
    }
    for(int i=0; i<26; i++) {
        if(chks[i]>=0) {
            sum[chks[i]]++;
            sum[chke[i]]--;
        }
    }
    int mx=0;
    for(int i=1; i<=n; i++) {
        sum[i]+=sum[i-1];
        mx=max(mx,sum[i]);
        if(mx>k) return 0&puts("YES");
    }
    puts("NO");
    return 0;
}
