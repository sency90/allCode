#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;
vector<string> lines;
string line;
stringstream ss;
string known = "the quick brown fox jumps over the lazy dog";
char dic[256], inv[256];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin >> tc; cin.ignore();
	getline(cin, line);
	while(tc--) {
		lines.clear();
		int cnt=0;
		bool hasAns = false;
		while(getline(cin, line)) {
			lines.emplace_back(line);
			if(line.empty()) break;
			if(hasAns) continue;
			if(line.size() != known.size()) continue;
			memset(dic, 0, sizeof(dic));
			memset(inv, 0, sizeof(inv));
            dic[' ']=' '; inv[' ']=' ';
			for(int i=0; i<line.size(); i++) {
				if((dic[line[i]] && dic[line[i]]!=known[i]) || (inv[known[i]] && inv[known[i]]!=line[i])) goto BAD;
				else dic[line[i]]=known[i], inv[known[i]]=line[i];
			}

			hasAns = true;
			continue;
BAD: ;
		}
		if(!hasAns) puts("No solution.");
		else {
			for(int i=0; i<lines.size(); i++) {
				if(lines[i].size() == 0) continue;
				for(int j=0; j<lines[i].size(); j++) {
					printf("%c", dic[lines[i][j]]);
				}
				puts("");
			}
		}
		if(tc>0) puts("");
	}
	return 0;
}
