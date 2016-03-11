#include <string>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
pair<int, int> info[1000];
bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first > rhs.first;
}
char str[1000][51];
int main() {
    int n;
    scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        info[i] = make_pair(1, i);
    }
    scanf("%s", str[0]);
    for(int i=1; i<n; i++) {
        scanf("%s", str[i]);
        for(int j=0; j<i; j++) {
            if(!strcmp(str[i],str[j])) {
                info[j].first++;
                break;
            }
        }
    }
    sort(info, info+n, cmp);
    int max = info[0].first;
    int idx[1000];
    memset(idx, -1, sizeof(idx));
    idx[0] = info[0].second;
    for(int i=1; i<n; i++) {
        if(max == info[i].first) {
            idx[i] = info[i].second;
        } else break;
    }
    vector<string> v;
    int i=0;
    for(; idx[i]!=-1; i++) {
        v.push_back(str[idx[i]]);
    }
    sort(v.begin(), v.end());
    cout << v[0];
    return 0;
}

