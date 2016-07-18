#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>
 
#pragma warning(disable:4996)
using namespace std;
 
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;
 
int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;
 
ll gcd(ll a, ll b) {
    return (a == 0) ? b : gcd(b%a, a);
}
 
vector <int> V;
ll cnt[1000050];
 
ll in[2050];
int main() {
    int N, K, i, j;
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
 
    for (i = 1; i <= K; i++) if (K % i == 0) V.push_back(i);
 
    ll ans = 0;
    for (i = N; i >= 1; i--) {
        for (auto it : V) if ((in[i] * it) % K == 0) ans += cnt[it];
        for (j = i + 1; j <= N; j++) cnt[gcd(in[i] * in[j], K)]++;
    }
    return !printf("%lld\n", ans);
}
