//이 문제는 sqrt decomposition 문제다.
//물론 segment tree로도 풀리는 것으로 알고 있다.
//
//여기서 문제가 되는 것은 최소값이나 최대값 구하는 평방분할처럼
//그룹의 대표값이 하나만으로 정의되지 않는다는 점이다.
//여기서는 색깔의 다채도라는 값의 합을 저장해야 하는데,
//그룹의 일부분만 물어보는 쿼리가 들어오는 경우에는
//결국 완전 다시 구해야 하는것 같은 느낌이 든다.
//만약 다시구하게 된다면 당연히 WA를 받는다.
//그럼 어떻게 해야 할까?
//
//그룹이 통째로 갱신될때 저장하는 다채도의 합을 gf라 하고,
//그룹의 일부만 갱신될때 각각의 다채도의 합을 f라 하면,
//각각의 경우에 gf와 f를 갱신시키면서, gfsum은 두 경우 모두에서 갱신시켜 주면 된다.
//
//그 다음 쿼리가 들어왔을때 그룹 통째로를 물어보는 쿼리가 들어오면 gfsum을 그냥 반환하기만 하면 되고,
//그게 아니라면
#include <stdio.h>
#include <cmath>
using namespace std;
#define MAXN 100001
#define GROUP 317

int gn[MAXN], b[GROUP], e[GROUP];
int c[MAXN], gc[GROUP];
long long gf[GROUP], gfsum[GROUP], f[MAXN];
long long ABS(long long x) {
    if(x<0LL) return -x;
    else return x;
}

int main() {
    long long x;
    int n, m, type, l, r;
    scanf("%d%d",&n,&m);
    int root = sqrt(n);
    for(int i=1; i<=n; i++) {
        c[i]=i; gn[i]=i/root; //root에 0이 들어가지 않는지 잘 생각하면서 써야 한다. 평방분할 할때엔 0번째 인덱스를 사용하지 말자.
        if(!b[gn[i]]) b[gn[i]]=i;
        e[gn[i]]=i;
    }
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&type,&l,&r);
        if(type == 1) {
            scanf("%lld", &x);
            for(int z=l; z<=r; z++) {
                if(b[gn[z]]==z && e[gn[z]]<=r) {
                    //group을 통째로 바꿔야 한다.
                    if(gc[gn[z]]) { //이전에 그룹 색깔이 통째로 바뀌었다면
                        gfsum[gn[z]] += ABS(gc[gn[z]]-x) * (e[gn[z]]-b[gn[z]]+1LL);
                        gf[gn[z]] += ABS(gc[gn[z]]-x); //group이 같이 함께 올라간 다채도의 합을 gf가 가지고 있다.
                    } else { //이전에 그룹 색깔이 개별적으로 바뀌었다면
                        //전부 일일이 바꿔줘야 함
                        for(int k=b[gn[z]]; k<=e[gn[z]]; k++) {
                            if(gc[gn[z]]) c[k] = gc[gn[k]];
                            gfsum[gn[k]] += ABS(c[k]-x);
                            f[k] += ABS(c[k]-x); //f에는 개별적으로 올라간 다채도의 합이 들어있다.
                            c[k] = x;
                        }
                    }
                    gc[gn[z]] = x; //해당 그룹의 색깔을 통째로 바꿔준다.
                    z = e[gn[z]]; //다음 그룹으로 한번에 건너 뛴다. (여기서 1더하지 않도록 주의해야 한다. for()에서 z++을 하고 있으니까!!)
                } else { //group의 정보가 개별적으로 갱신되어야 한다면,
                    if(gc[gn[z]]) {
                        for(int k=b[gn[z]]; k<=e[gn[z]]; k++) {
                            c[k] = gc[gn[z]];
                        }
                        gc[gn[z]] = 0LL; //그룹이 가지는 컬러가 모두 같은 경우가 아니란 뜻.
                    }
                    gfsum[gn[z]] += ABS(c[z]-x);
                    f[z] += ABS(c[z]-x);
                    c[z] = x;
                }
            }
        } else { //if type is 2
            long long ans = 0LL;
            for(int z=l; z<=r; z++) {
                if(b[gn[z]]==z && e[gn[z]]<=r) {
                    ans += gfsum[gn[z]];
                    z = e[gn[z]];
                } else {
                    ans += gf[gn[z]] + f[z];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
