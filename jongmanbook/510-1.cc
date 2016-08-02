#include <stdio.h>
#include <algorithm>
int r[201], p[201];
using namespace std;
int gcd(int b, int l) {return (l==0)?b:gcd(l,b%l);}
//X = max(put[i]/recipe[i])라 하자. 즉 X는 비율중의 최대를 의미한다.
//우리는 모든 p[i]/r[i]가 X라는 비율보다 크거나 같도록 v[i]만큼 마법약을 추가해야 한다.
//즉, X<=Y 이면서, 모든 i에 대해 Y=(p[i]+v[i])/r[i] 를 만족하는 최소 Y를 알고 싶은 것이다. (문제의 조건에 따라 Y의 최소값은 1임을 주의하자.)
//여기서 Y를 a/b라고 하면 a/b = (p[i]+v[i])/r[i] 이고, r[i]*a/b = p[i]+v[i]가 된다.
//여기서 p[i], v[i]는 정수이므로 r[i]*a/b는 정수가 되어야 한다. 즉, b는 gcd(r[i])인 셈이다.
//그럼 이제 b를 g라고 표기하자.
//그럼 지금 우리가 v[i](추가해야하는 최소 마법약)를 구하는 것이 최종 목표인데, 아직 모르는 값 a가 하나 남아있다.
//다시 위의 식을 살펴보면, X<=Y=(a/g) 이고 a,g는 정수 이므로, g*X<=a를 만족하는 최소 정수 a를 찾으면 된다.
//이때 조심해야 할 부부은 X가 max(put[i]/recipe[i])라고 해서 X를 max(ceil(put[i]/recipe[i]))라고 생각하면 안된다.
//구간 [p[i]/r[i], ceil(p[i]/r[i]))에서 recipe[i]/g가 put[i]와 약분되는 경우가 있기 때문이다.
//따라서 g*X<=a를 만족 하는 최소 정수 a는 max(ceil(g*p[i]/r[i]))이다.
//아래의 코드에서 a는 mx라고 표기되었다.
//따라서 r[i]*a/g = p[i]+v[i]이므로 v[i]=r[i]*a/g - p[i]    =>    v[i] = r[i]*max(ceil(g*p[i]/r[i])/g - p[i] 이다.
//여기서 올림함수(ceil)안에 있는 g와 그 함수 바깥에 있는 g를 약분해버리는 병신같은 짓거리를 해서는 안된다.
//이제 v[i]를 순서대로 출력해주기만 하면 된다.
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, mx=1;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &r[i]);
        for(int i=0; i<n; i++) scanf("%d", &p[i]);
        int g = r[0];
        for(int i=1; i<n; i++) g = gcd(g, r[i]);
        for(int i=0; i<n; i++) mx = max(mx, (g*p[i]+r[i]-1)/r[i]);
        for(int i=0; i<n; i++) printf("%d ", mx*r[i]/g-p[i]);
        puts("");
    }
    return 0;
}
