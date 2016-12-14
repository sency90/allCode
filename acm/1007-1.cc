#include <stdio.h>
#include <math.h>
struct dot {
    double x, y;
    dot(){} dot(double x, double y):x(x),y(y){}
};
dot ary[23];
dot s;
double min;
void dfs(int k, int p, double x, double y, int n) {
    if (k==n) {
        if (p!= n/2) return;
        if (sqrt((2*x-s.x)*(2*x-s.x) + (2*y-s.y)*(2*y-s.y)) < min)
            min = sqrt((2*x-s.x)*(2*x-s.x) + (2*y-s.y)*(2*y-s.y));
        return;
    }
    dfs(k+1, p, x, y, n); // 선택x
    dfs(k+1, p+1, x + ary[k].x, y + ary[k].y, n); // plus 선택
}
int main() {
    int n, t;
    double a, b;
    scanf("%d", &t);
    while (t--) {
        min = 3000000.0;
        s.x = 0; s.y = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &a, &b);
            ary[i] = dot(a, b);
            s.x += a;
            s.y += b;
        }
        dfs(0, 0, 0.0, 0.0, n);
        printf("%.6lf\n", min);
    }
    return 0;
}
