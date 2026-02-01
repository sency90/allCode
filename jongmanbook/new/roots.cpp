#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;
void Dif(vector<double> & cof, vector<double> & ret) {
    if(cof.size()==1) 
    ret.clear();
    ret.resize(cof.size());
    bool flag = true;
    for(int i=cof.size()-1; i>0; i--) {
        ret[i-1] = cof[i]*i;
    }
    for(int i=ret.size()-1; i>=0; i--) {
        if(ret[i]==0) ret.pop_back();
        else break;
    }
    if(ret.empty()) ret.push_back(0);
}
void MakeIntv(vector<pdd> & intv_list, const vector<double> & ex) {
    intv_list.emplace_back(-11.0,ex[0]);
    for(int i=0; i<ex.size()-1; i++) {
        intv_list.emplace_back(ex[i],ex[i+1]);
    }
    intv_list.emplace_back(ex.back(),11.0);
}
double Pow(double x, int n) {
    if(n==0) return 1.0;
    double ret = Pow(x, n / 2);
    if(n%2==0) return ret*ret;
    else return ret*ret*x;
}

double Eq(const vector<double> & cof, double x) {
    double ret = 0;
    for(int i=cof.size()-1; i>=0; i--) {
        ret += cof[i]*Pow(x,i);
    }
    return ret;
}

inline bool Is0(double x) {
    return fabs(x)<1e-9;
}

void Solve(vector<double> & cof, vector<double> & sol) {
    if(cof.size()==2) {
        sol.push_back(-cof[0]/cof[1]);
        return;
    }
    else if(cof.size()<2) return;
    vector<double> dif_cof;
    Dif(cof, dif_cof);

    vector<double> ex; //extremum
    Solve(dif_cof, ex);

    if(ex.empty()) return;

    vector<pdd> intv_list;
    MakeIntv(intv_list, ex);
    for(int i=0; i<intv_list.size(); i++) {
        double lo = intv_list[i].first;
        double hi = intv_list[i].second;
        double flo = Eq(cof,lo);
        double fhi = Eq(cof,hi);
        //실수 오차 때문에 아래 flo, fhi값이 0인지 따로 체크하지 않으면 중근 데이터에서 터질 수 있다.
        if(Is0(flo)) sol.push_back(lo);
        if(Is0(fhi)) sol.push_back(hi);
        if (flo * fhi < 0) {
            if (flo < 0) swap(lo, hi);
            for (int z = 0; z < 100; z++) {
                double mid = (lo + hi) / 2;
                if (Eq(cof, mid) >= 0) lo = mid;
                else hi = mid;
            }
            if (Is0(Eq(cof, lo))) sol.push_back(lo);
        }
    }
}
bool chk[7];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    vector<double> cof,sol;
    while(tc--) {
        int n; cin >> n;
        cof.clear(); cof.resize(n+1);
        for(int i=n; i>=0; i--) {
            cin >> cof[i];
        }
        sol.clear();
        Solve(cof, sol);

        if (!sol.empty()) {
            memset(chk, true, sizeof(chk));
            sort(sol.begin(), sol.end());
            for (int i = 1; i < sol.size(); i++) {
                if (Is0(sol[i] - sol[i - 1])) chk[i] = false;
            }
            n = sol.size();
            for (int i = 1; i < n; i++) {
                if (!chk[i]) sol[i] = sol[--n];
            }
            for(int i=0; i<n; i++) if(Is0(sol[i])) sol[i]=0.0;

            sort(sol.begin(), sol.begin()+n);
            for (int i = 0; i < n; i++) {
                printf("%.10lf ", sol[i]);
            }
            puts("");
        }
    }
    return 0;
}