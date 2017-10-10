#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,  s, pos[100001], v[100001], face[100001];
double mn=1e6;
bool judge(double x) {
    double lmn=1e6,rmn=1e6;
    for(int i=0; i<n; i++) {
        if(face[i]==1) {
            if(pos[i]<=x) {
                double tm = double(pos[i]-x)/(v[i]-s);
                double md = x - tm*s;
                if(md>=0.0) lmn = min(lmn, md/double(v[i]+s)+tm);
                else lmn = min(lmn,double(pos[i])/v[i]);
            } else {
                lmn = min(lmn, double(pos[i])/v[i]);
            }
        } else {
            if(pos[i]>=x) {
                double tm = (pos[i]-x)/(s-v[i]);
                double md = 1e6 - (x + tm*s);
                if(md>=0.0) rmn = min(rmn, md/double(s+v[i])+tm);
            } else {
                rmn = max(rmn, (1e6-pos[i])/v[i]);
            }
        }
    }
    return max(lmn,rmn)<mn;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> pos[i] >> v[i] >> face[i];
    }

    double minimum=1e6;
    double lo=0, hi=1e6;
    for(int i=0; i<100; i++) {
        double md = (lo+hi)/2.0;
        if(judge(md)) hi=md;
        else lo=md;
    }
    printf("%.7lf\n", lo);
    return 0;
}
