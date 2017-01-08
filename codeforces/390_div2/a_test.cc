#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <map>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false)
#define sci(d) scanf("%d", &d)
#define scs(s) scanf("%s", &s)

#define SINF 20000000
#define INF 200000000
#define LLINF 900000000000000000LL
#define X first
#define Y second
#define MAX 1001
#define MOD 1000000007LL
#define endl "\n"
#define ALL(a) (a).begin(), (a).end()
#define pr(n) operator[](n);

typedef long long ll;
typedef pair<int, int> pi;

int Q, N, M, K, L;
int A[101];

int main() {
    FAST_IO;
    cin >> N;
    int psum = 0;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        for (int k = 0; k <= i; k++) a += A[k];
        for (int l = i + 1; l < N; l++) b += A[l];
        if (a != 0 && b != 0) {
            cout << "YES" << endl << 2 << endl;
            cout << 1 << " " << i + 1 << endl;
            cout << i + 2 << " " << N << endl;
            return 0;
        }
    }
    cout << "NO";

}
