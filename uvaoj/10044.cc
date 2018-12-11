#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
string line;
stringstream ss;
const string ER = "Erdos, P.";
map<string, int> idx;
vector<vector<int>> g;
vector<int> v, ans;
queue<int> q;
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    string name, lname, fname;

    int tc; cin >> tc;
    for(int z=1; z<=tc; z++) {
        g.clear();
        idx.clear();
        printf("Scenario %d\n", z);
        int p,n; cin >> p >> n;
        getline(cin, line); //scan '\n'

        int cnt=0;
        for(int i=0; i<p; ) {
            v.clear();
            getline(cin, line);
            //printf("[%lu] %s\n", line.size(), line.c_str());
            if(line.size()==0) continue;
            else i++;

            ss.clear(); ss.str(line);
            getline(ss, line, ':');
            ss.clear(); ss.str(line);
            string prevName="";
            while(true) {
                getline(ss, fname, ','); getline(ss, lname, ',');
                if(fname.size()>0 && fname[0]==' ') fname = fname.substr(1);
                name = fname + ',' + lname;
                if(prevName == name) break;
                else prevName = name;

                //printf("[%d] %s\n", i, name.c_str());
                if(idx.count(name) == 0) idx[name] = cnt++;
                v.push_back(idx[name]);
            }

            while(g.size()<=cnt) g.push_back(vector<int>());
            for(int i=0; i<v.size(); i++) {
                for(int j=i+1; j<v.size(); j++) {
                    g[v[i]].push_back(v[j]);
                    g[v[j]].push_back(v[i]);
                }
            }
        }

        ans.clear(); ans.resize(cnt+1,-1);
        int mainIdx = idx[ER];
        q.push(mainIdx);
        int lv=0;
        while(!q.empty()) {
            int sz = q.size();
            lv++;
            for(int zz=0; zz<sz; zz++) {
                int x = q.front(); q.pop();
                for(int i=0; i<g[x].size(); i++) {
                    int y = g[x][i];
                    if(ans[y] != -1) continue;
                    ans[y] = lv;
                    q.push(y);
                }
            }
        }

        for(int i=0; i<n; ) {
            getline(cin, name);
            if(name.empty()) continue;
            else i++;
            int curIdx = -1;
            if(idx.count(name)>0) curIdx = idx[name];
            //printf("%s -> %d\n", name.c_str(), curIdx);

            if(curIdx!=-1 && ans[curIdx]!=-1) printf("%s %d\n", name.c_str(), ans[curIdx]);
            else printf("%s infinity\n", name.c_str());
        }
    }

    return 0;
}
