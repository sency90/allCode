#include <stdio.h>
#include <string.h>
#include <vector>
#include <limits.h>
#define LIM 500000
using namespace std;
vector<int> v;
bool broken[10];
bool isBr(int x) {
    if(x==0) {
        return broken[x];
    }
    while(x!=0) {
        if(!broken[x%10]) x/=10;
        else return true;
    } return false;
}
int counting(int x) {
    if(x==0) return 1;
    int cnt=0;
    while(x!=0) {
        cnt++;
        x/=10;
    }
    return cnt;
}
int main() {
    memset(broken, false, sizeof(broken));
    int n, m, d, worst, ch=INT_MAX, cnt, c=0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        broken[d] = true;
        c++;
    }
    if(n==100) {
        printf("0");
        return 0;
    }

    if(n > 100) worst = n-100;
    else worst = 100-n;

    if(c==10) {
        printf("%d", worst);
        return 0;
    } else if(c==0) {
        printf("%d", worst<counting(n)?worst:counting(n));
        return 0;
    }

    for(int i=n; i<n+worst; i++) {
        if(!isBr(i)) {
            ch = i;
            break;
        }
    }

    for(int i=n-1; i>n-worst && i>=0; i--) {
        if(!isBr(i)) {
            if(n-i <= ch-n) ch = i;
            break;
        }
    }

    if(ch==INT_MAX) {
        printf("%d", worst);
        return 0;
    }

    if(ch-n < 0) cnt = n-ch;
    else cnt = ch-n;
    cnt += counting(ch);
    if(cnt > worst) cnt = worst;
    printf("%d", cnt);
    return 0;
}
