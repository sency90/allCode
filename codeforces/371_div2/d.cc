#include <iostream>
#include <algorithm>
using namespace std;
int lower=1, upper, N;
pair<int,int> bs(int idx) {
    int v[]={lower,lower,upper,upper};
    int l=lower, r=upper, cnt=0;
    pair<int,int> ret;

    for(int i=0; i<=N; i++) {
        v[idx] = (l+r)>>1;
        cout << '?';
        for(int i=0; i<4; i++) {
            cout << " " <<v[i];
        } cout << endl;
        cin >> cnt;
        if(idx<=1) {
            if(cnt==2) l=v[idx];
            else r=v[idx];
        } else {
            if(cnt>=1) r=v[idx];
            else l=v[idx];
        }
    }
    //printf("#### %d %d\n", l,r);
    if(idx<=1) ret.first = l;
    else ret.first=l+1;

    l=lower, r=upper;
    cnt=0;
    for(int i=0; i<=N; i++) {
        v[idx] = (l+r)>>1;
        cout << '?';
        for(int i=0; i<4; i++) {
            cout << " " << v[i];
        } cout << endl;
        cin >> cnt;
        if(idx<=1) {
            if(cnt==0) r=v[idx];
            else l=v[idx];
        } else {
            if(cnt==2) r=v[idx];
            else l=v[idx];
        }
    }
    if(idx<=1) ret.second = l;
    else ret.second = l+1;
    //printf("---------- %d %d -----------\n", ret.first,ret.second);
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    upper = n;
    for(int i=0; i<=16; i++) {
        if(n<=(1<<i)) {
            N=i;
            break;
        }
    }

    pair<int,int> bound[4];
    for(int i=0; i<4; i++) {
        bound[i] = bs(i);
    }
    cout << '?';
    for(int i=0; i<4; i++) {
        cout << ' '<< bound[i].first;
    } cout << endl;
    int cnt;
    cin >> cnt;
    cout << '!';
    //if(cnt==1) {
        for(int i=0; i<4; i++) cout << ' '<< bound[i].first;
        for(int i=0; i<4; i++) cout << ' '<< bound[i].second;
        /*
    } else {
        for(int i=0; i<2; i++) cout << ' '<< bound[i].second;
        for(int i=2; i<4; i++) cout << ' '<< bound[i].first;
        for(int i=0; i<2; i++) cout << ' '<< bound[i].first;
        for(int i=2; i<4; i++) cout << ' '<< bound[i].second;
    }
    */
    cout << endl;
    return 0;
}
