#include <bits/stdc++.h>
using namespace std;
string words[501];
double B[501], T[501][501], M[501][501];
unordered_map<string, int> udic;
int result[101]; // result[n]: 분류기가 분류한 결과에서 n번째 단어로 분류된 words 배열의 index

int m;
int CHKVAL;
int chk[101][501];
double dp[101][501];
int ans[101][501];

void GetAns(int n, int x) {
    if(n==0) return;
    int prv_x = ans[n][x];
    GetAns(n-1, prv_x);
    printf("%s ", words[prv_x].c_str());
}

double f(int n, int x) { //f(n,x) = log(n번째 단어가 words[x]로 끝나는 최대 확률)
    if(n == 0) {
        return B[x] + M[x][result[n]];
    }
    double& ret = dp[n][x];
    if(chk[n][x] == CHKVAL) return ret;
    chk[n][x] = CHKVAL;

    ret = log(0.0); //-inf
    double tmp;
    ans[n][x] = -1;
    for(int i = 0; i < m; i++) {
        tmp = f(n-1, i) + T[i][x] + M[x][result[n]];
        //T[i][x] = log(words[i]다음에 words[x]가 올 확률)
        //M[x][result[n]] = log(words[x]를 words[result[n]]으로 판독할 확률률
        if(ret < tmp) {
            ret = tmp;
            ans[n][x] = i;
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> m >> q;
    for(int i = 0; i < m; i++) {
        cin >> words[i];
        udic[words[i]] = i;
    }
    //words[m]은 '끝'을 의미하도록 설정

    double val;
    for(int i = 0; i < m; i++) {
        cin >> val;
        B[i] = log(val);
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> val;
            T[i][j] = log(val);
        }
        T[i][m]=log(1.0); //모든 단어에서 끝날 수 있음을 표현.
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> val;
            M[i][j] = log(val);
        }
    }
    M[m][m]=log(1.0);

    string qword;
    for(int i = 0; i < q; i++) {
        CHKVAL++;
        int n; cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> qword;
            result[j] = udic[qword];
        }
        result[n] = m;

        f(n,m);
        GetAns(n, m);
        puts("");
    }
    return 0;
}