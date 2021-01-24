#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[19],b[19],c[19];
int cnta[10],idx[19];
int main() {
    scanf("%s%s",a,b);
    int alen = strlen(a);
    int blen = strlen(b);
    for(int i=0; i<alen; i++) {
        cnta[a[i]-'0']++;
    }

    c[alen]=0;
    bool issame = (alen<blen)?false:true;
    for(int i=0; i<alen; i++) idx[i] = 9;
    for(int i=0; i<alen; i++) {
        for(int &j=idx[i]; j>=0; j--) {
            if(cnta[j]) {
                if(issame) {
                    if(b[i]-'0'>j) issame = false;
                    else if(b[i]-'0'<j) continue;
                }
                c[i] = j+'0';
                cnta[j]--;
                break;
            }
        }
        if(idx[i]<0) {
            idx[i] = 9;
            cnta[idx[(--i)--]--]++;
        }
    }

    printf("%s\n", c);
    return 0;
}
