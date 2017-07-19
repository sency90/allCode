#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<string> dict;
vector<pair<double,string> > ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    string s;
    char c;
    for(int z=1;;z++) {
        dict.clear();
        cin >> n >> m >> c;
        if(n==0 && m==0) return 0;
        for(int i=0; i<n; i++) {
            getline(cin, s);
            dict.insert(s);
        }
        double d; int r; string name;
        int mx=0;
        for(int i=0; i<m; i++) {
            cin >> name >> d >> r >> c;
            int cnt=0;
            for(int j=0; j<r; j++) {
                getline(cin, s);
                if(dict.count(s)) cnt++;
            }

            if(mx<cnt) {
                mx=cnt;
                ans.clear();
                ans.push_back(pair<double,string>(d,name));
            } else if(mx==cnt) {
                ans.push_back(pair<double,string>(d,name));
            }
        }
        sort(ans.begin(), ans.end());
        printf("RFP #%d\n",z);
        printf("%s\n", ans[0].second.c_str());
        puts("");
    }
    return 0;
}
