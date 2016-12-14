#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
map<string, vector<int>> mp;
set<string> m;
//char str[201];
string str;
vector<vector<int>> table;
void split(const string& str, const string& delim, vector<string>& parts) {
	size_t start, end = 0;
	while (end < str.size()) {
		start = end;
		while (start < str.size() && (delim.find(str[start]) != string::npos)) {
			start++;  // skip initial whitespace
		}
		end = start;
		while (end < str.size() && (delim.find(str[end]) == string::npos)) {
			end++; // skip to end of word
		}
		if (end-start != 0) {  // just ignore zero-length strings.
			parts.push_back(string(str, start, end-start));
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("/Users/lian/Downloads/groceries.csv", "r", stdin);
	int row=0;
	getline(cin, str);
	//while(~scanf("%[^\n]\n", str)) {
	while(true) {
		getline(cin,str);
		if(str[0]=='0') break;
		row++;
		string s;

		split(str, s, ",");
			cout << s;
			//v.push(s);
			//m.insert(s);
			//p[s].push_back(row);
		}
	}
	//table.resize(row+1, vector<int>(m.size()+1));
	return 0;

	/*
	   int col=0;
	   for(auto &p: m) {
	   cout << p <<", ";
	   col++;
	   for(auto &q: mp) {
	   vector<int> &t = q.second;
	   for(int i=0; i<t.size(); i++) {
	   table[col][t[i]]=1;
	   }
	   }
	   }
	   cout << "\n";

	   for(int i=0; i<row; i++) {
	   cout << i << ", ";
	   for(int j=0; j<col; j++) {
	   if(table[i][j]) cout << "1, ";
	   else cout << "0, ";
	   }
	   cout << "\n";
	   }
	   */
	//return 0;
}
