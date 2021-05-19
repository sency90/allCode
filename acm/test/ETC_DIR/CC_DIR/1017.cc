#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > v;
vector<int> fi, se, start;
int am[51],bm[51],d[51];
bool notPrime[2001], chk[51];
void getPrime() {
    notPrime[0]=notPrime[1]=true;
    for(int i=2; i*i<=2000; i++) {
        if(notPrime[i]) continue;
        for(int j=i*i; j<=2000; j+=i) {
            notPrime[j]=true;
        }
    }
}
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x]=true;
    for(auto &y: v[x]) {
        if(bm[y]==-1||bipartite(bm[y])) {
            am[x]=y; bm[y]=x;
            return true;
        }
    }
    return false;
}
int main() {
    getPrime();
    int n; scanf("%d", &n);
    bool firstodd;
    for(int i=0; i<n; i++) {
        scanf("%d",&d[i]);
        if(i==0) firstodd=(d[i]&1);
        if((d[i]&1)==firstodd) fi.push_back(i);
        else se.push_back(i);
    }
    if(fi.size()!=se.size()) { puts("-1"); return 0; }

    v.resize(fi.size(), vector<int>());
    for(int i=0; i<fi.size(); i++) {
        for(int j=0; j<se.size(); j++) {
            if(!notPrime[d[fi[i]]+d[se[j]]]) {
                if(i==0) start.push_back(j);
                else v[i].push_back(j);
            }
        }
    }

    priority_queue<int> mnh;
    for(int i=0; i<start.size(); i++) {
        int ans=0;
        memset(am,-1,sizeof(am));
        memset(bm,-1,sizeof(bm));
        if(i==0) v[0].push_back(start[i]);
        else v[0][0]=start[i];

        for(int j=0; j<fi.size(); j++) {
            memset(chk, false, sizeof(chk));
            if(bipartite(j)) ans++;
            else break;
        }
        if((ans<<1)==n) mnh.push(-d[se[start[i]]]);
    }

    if(mnh.empty()) puts("-1");
    else {
        while(!mnh.empty()) {
            printf("%d ", -mnh.top());
            mnh.pop();
        }
    }
    return 0;
}
