#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> > v;
vector<int> sccId, discovered;
stack<int> st;
int sccCounter, vertexCounter;

int scc(int x) {
    int ret = discovered[x] = vertexCounter++;
    st.push(x);
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(discovered[y] == -1) ret = min(ret, scc(y));
        else if(sccId[y] == -1) ret = min(ret, discovered[y]);
    }

    if(ret == discovered[x]) {
        while(true) {
            int t = st.top(); st.pop();
            sccId[t] = sccCounter;
            if(t == x) break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> tarjanSCC() {
    sccId = discovered = vector<int>(v.size(), -1);
    sccCounter = vertexCounter = 0;
    for(int i=0; i<v.size(); i++) {
        if(discovered[i] == -1) scc(i);
    }
    return sccId;
}

int main() {
    ios::sync_with_stdio(false);
    int n=7;
    v.resize(n, vector<int>());
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
    tarjanSCC();
    for(int i=0; i<7; i++) {
        printf("%d: %d\n", i, sccId[i]);
    }
    return 0;
}
