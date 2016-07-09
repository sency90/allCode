#include <stdio.h>
const long long MOD = 1000LL;
struct eq{
    long long a, b;
    eq operator*(eq rhs) {
        eq ret;
        ret.a = (a*rhs.a + 5*b*rhs.b)%MOD;
        ret.b = (a*rhs.b + b*rhs.a)%MOD;
        return ret;
    }
};
eq spow(eq e, int n) {
    //이 부분에서 조심해야 한다.
    //1629번 곱셈이란 문제는 n==0일때 리턴해도 멀쩡한 값을 리턴하지만,
    //이 경우는 불가능하다.
    //왜냐하면 n==0인경우 e.a=1이고 e.b=0인데 이렇게 하면 0에 관한 값을 계속 곱해나가기 떄문에
    //a와 b에 해당하는 값이 n이 커져도 변하지 않게된다.
    //따라서 n은 1에서 리턴을 해줘야 하며, 문제에서 n>=2였으므로 n이 0일때를 고려해줄 필요도 없다.
    //뿐만 아니라 f(e,n/2)로 인해 n값이 0이 들어올 수도 없다.
    //왜냐하면 n은 0이 들어오려면 반드시 n은 1인 상태를 거쳐야만 하는데,
    //해당 상태를 if(n==1)로 걸러주고 있기 때문이다.
    if(n==1) return e;

    eq ret = spow(e, n/2);
    ret = ret*ret;
    if(n%2) ret = ret*e;

    return ret;
}
int main() {
    int t, n;
    scanf("%d", &t);
    eq e;
    for(int z=1; z<=t; z++) {
        scanf("%d", &n);
        e.a = 3; e.b=1;
        printf("Case #%d: %03lld\n", z, (2LL*spow(e,n).a - 1LL)%MOD);
    }
    return 0;
}
