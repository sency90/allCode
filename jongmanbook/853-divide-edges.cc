//JMBook 849 page graph -> dfs tree / divide-edges
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<pair<int, int> > tree, ford, back, cross;
vector<vector<int> > v;
vector<bool> fin;
vector<int> discovered;
int counter=0;
void dfs(int x) {
    discovered[x] = ++counter;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(discovered[y]) {
            if(discovered[y] > discovered[x]) ford.push_back(make_pair(x,y));
            else if(fin[y]) cross.push_back(make_pair(x,y));
            else back.push_back(make_pair(x,y));
            continue;
        } else {
            tree.push_back(make_pair(x,y));
            dfs(y);
        }
    }
    fin[x] = true;
}
int main() {
    int n=7;
    v.resize(n, vector<int>());
    discovered.resize(n, 0);
    fin.resize(n, false);
    v[0].push_back(1);
    v[0].push_back(4);
    v[0].push_back(5);
    v[0].push_back(6);
    v[5].push_back(3);
    v[5].push_back(6);
    v[6].push_back(3);
    v[4].push_back(2);
    v[1].push_back(2);
    v[2].push_back(0);
    dfs(0);

    cout << "TREE EDGE: ";
    for(auto &p : tree) cout << "(" << p.first << ", " << p.second << ") ";
    puts("");
    cout << "ford EDGE: ";
    for(auto &p : ford) cout << "(" << p.first << ", " << p.second << ") ";
    puts("");
    cout << "BACK EDGE: ";
    for(auto &p : back) cout << "(" << p.first << ", " << p.second << ") ";
    puts("");
    cout << "CROSS EDGE: ";
    for(auto &p : cross) cout << "(" << p.first << ", " << p.second << ") ";
    puts("");
    return 0;
}
