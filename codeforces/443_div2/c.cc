#include <cstdio>
using namespace std;
int v[10];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<10; i++) v[i]=2;
    while(n--) {
        char s[2]; int t;
        scanf("%s %d", s, &t);
        if(s[0]=='|') {
            for(int i=0; i<10; i++) {
                if((t>>i)&1) v[i]=1;
            }
        } else if(s[0]=='&') {
            for(int i=0; i<10; i++) {
                if(!((t>>i)&1)) v[i]=0;
            }
        } else {
            for(int i=0; i<10; i++) {
                if((t>>i)&1) v[i]^=1;
            }
        }
    }

    int AND=0,OR=0,XOR=0;
    for(int i=0; i<10; i++) {
        if(v[i]==0) AND |= (1<<i);
        else if(v[i]==1) OR |= (1<<i);
        else if(v[i]==3) XOR ^= (1<<i);
    }

    printf("3\n");
    printf("& %d\n", AND^1023);
    printf("| %d\n", OR);
    printf("^ %d\n", XOR);
    return 0;
}
