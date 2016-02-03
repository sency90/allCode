#include <cstdio>
#include <algorithm>
#define M 1000000000000000000UL
using namespace std;

struct bInt {
    unsigned long long a, b;
    bInt() : a(0), b(0) {}
    bInt(unsigned long long n) : a(n), b(0) {}

    inline bool operator==(const bInt &val) {
        return a == val.a && b == val.b;
    }

    inline bInt &operator+(const bInt &val) {
        b = b + val.b + (a + val.a) / M;
        a = (a + val.a) % M;

        return *this;
    }

    inline bInt &operator+=(const bInt &val) {
        *this = this->operator+(val);
        return *this;
    }

    void print() {
        if(b == 0) printf("%llu", a);
        else printf("%llu%018llu", b, a);
    }
};

bInt z(0), cache[101][51];

bInt combi(int n, int m) {
    if(m == 0) return 1;
    if(cache[n][m] == z) {
        int n2 = n-1;
        int m2 = m-1;
        int m3 = m;
        if(n2-m2 < m2) m2 = n2-m2;
        if(n2-m3 < m3) m3 = n2-m3;
        cache[n][m] = combi(n2, m2) + combi(n2, m3);
    }
    return cache[n][m];
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n-m < m) m = n-m;
    combi(n, m).print();
    printf("\n");
    return 0;
}
