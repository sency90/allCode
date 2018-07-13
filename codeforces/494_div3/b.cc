#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
string s;
int main() {
    int a,b,x,tog; scanf("%d%d%d",&a,&b,&x);
    if(a<b) tog=0, s="1", b--;
    else tog=1, s="0", a--;

    for(int i=0; i<x; i++) {
        s+=('0'+tog);
        if(tog) b--;
        else a--;
        tog^=1;
    }
    while(a--) {
        if(s[0]=='0') s="0"+s;
        else if(s.size()>1 && s[1]=='0') s=s.substr(0,1)+"0"+s.substr(1);
        else s+="0";
    }
    int onePos=-1;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='1') onePos = i;
    }
    while(b--) {
        if(onePos==0) s="1"+s;
        else s=s.substr(0,onePos)+"1"+s.substr(onePos);
    }
    printf("%s", s.c_str());
    return 0;
}
