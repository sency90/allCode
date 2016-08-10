#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
vector<vector<vector<int> > > v;
vector<vector<int> > ed;
vector<string> s;
vector<bool> chk;
int out[26], in[26];
void dfs(int i, vector<int> &circuit) {
    for(auto &j : ed[i]) {
        for(auto &p: v[i][j]) {
            if(chk[p]) continue;
            chk[p] = true;
            dfs(s[p][s[p].size()-1]-'a', circuit);
            circuit.push_back(p);
        }
    }
}
bool chkEuler() {
    int isStart=0, isEnd=0;
    for(int i=0; i<26; i++) {
        if(out[i]-in[i] == 1) isStart++;
        else if(in[i]-out[i] == 1) isEnd++;
        else if(in[i]==out[i]) continue;
        else return false;
    }
    return (isStart==1 && isEnd==1)||(isStart==0&&isEnd==0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc, n, l, r;

    cin >> tc;
    while(tc--) {
        cin >> n;
        memset(out, 0, sizeof(out));
        memset(in, 0, sizeof(in));
        v.clear(); v.resize(26, vector<vector<int> >(26, vector<int>()));
        ed.clear(); ed.resize(26, vector<int>());
        s.clear(); s.resize(n);

        for(int i=0; i<n; i++) {
            cin >> s[i];
            l=s[i][0]-'a'; r=s[i][s[i].size()-1]-'a';
            ed[l].push_back(r);
            v[l][r].push_back(i);
            out[l]++; in[r]++;
        }
        if(!chkEuler()) { cout << "IMPOSSIBLE\n"; continue; }

        bool allEven = true, hasAns = true;
        chk.clear(); chk.resize(n, false);
        vector<int> circuit;
        for(int i=0; i<26; i++) {
            if(out[i]==in[i]+1) {
                dfs(i, circuit);
                allEven = false;
                if(circuit.size() != n) hasAns = false;
                break;
            }
        }
        if(allEven) {
            for(int i=0; i<26; i++) {
                if(out[i]>0) {
                    dfs(i, circuit);
                    if(circuit.size() != n) hasAns = false;
                    break;
                }
            }
        }
        if(!hasAns) { cout << "IMPOSSIBLE\n"; continue; }

        reverse(circuit.begin(), circuit.end());
        for(auto &p : circuit) {
            cout << s[p] << " ";
        }
        cout << "\n";
    }
    return 0;
}
