#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> pii;
vector<string> str; //suspicious string set & malicious string set
map<string, vector<int>> ss;
vector<pii> r; //rank
int main() {
    ios::sync_with_stdio(false);
    int l, k, base=0;
    printf("Input parameter L: "); cin >> l;
    printf("Input parameter K (K must be less than or equal to L): "); cin >> k;
    if(k>l) return -1&puts("K must be less than or equal to L !!!");

    string line;
    ifstream infs("./suspicious.txt");
    puts("Suspicious Strings:");
    while(getline(infs, line)) {
        int tl = min(l,(int)line.size());
        printf("%s ", line.c_str());
        if(line.size()<k) continue;
        for(int i=0; i+tl<=line.size(); i++) {
            str.push_back(line.substr(i,tl));
            for(int j=max(0,i+k-tl); j<=i; j++) {
                ss[line.substr(i,k)].push_back(j+base);
            }
        }
        base+=line.size()-tl+1;
    } puts("\n");

    int sz = base;
    r.resize(sz,pii(0,0));
    for(int i=0; i<sz; i++) r[i].second=i;

    puts("Malicious Strings:");
    ifstream infm("./malicious.txt");
    while(getline(infm, line)) {
        printf("%s ", line.c_str());
        if(line.size()<k) continue;
        for(int i=0; i+k<line.size(); i++) {
            for(int p: ss[line.substr(i,k)]) r[p].first++;
        }
    } puts("\n");

    puts("RESULT:");
    sort(r.begin(), r.end());
    for(int i=0; i<sz; i++) {
        printf("%s %d\n", str[r[i].second].c_str(), r[i].first);
    }
    return 0;
}
