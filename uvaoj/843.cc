#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef pair<int,int> pii;
int chg(char c) { return c-'a'; }
vector<string> wList, vList;
vector<vector<int>> w;
vector<vector<int>> g;

int dic[26], revDic[26];
bool selfValid(const string &a, const string &b) {
	if(a.empty()) return false;
	if(a.size()!=b.size()) return false;

	memset(dic,0xff,sizeof(dic));
	memset(revDic,0xff,sizeof(revDic));
	for(int i=0; i<a.size(); i++) {
		int x=chg(a[i]),y=chg(b[i]);
		if(dic[x] == -1) dic[x]=y;
		else if(dic[x] != y) return false;
		if(revDic[y] == -1) revDic[y]=x;
		else if(revDic[y] != x) return false;
	}
	return true;
}
void graphModeling() {
	for(int i=0; i<vList.size(); i++) {
		int len = vList[i].size();
		for(int j=0; j<w[len].size(); j++) {
			if(!selfValid(vList[i],wList[w[len][j]])) continue;
			g[i].emplace_back(w[len][j]);
		}
	}
}
vector<pii> ans;
bool chk[40];
void regi(vector<pii> &dict, vector<pii> &revDict, const string &a, const string &b) {
	for(int i=0; i<a.size(); i++) {
		int x = chg(a[i]),y=chg(b[i]);
		dict[x].first=y; revDict[y].first=x;
		dict[x].second++; revDict[y].second++;
	}
}
void unregi(vector<pii> &dict,vector<pii> &revDict,const string &a,const string &b) {
	for(int i=0; i<a.size(); i++) {
		int x= chg(a[i]),y=chg(b[i]);
		dict[x].second--; revDict[y].second--;
	}
}
bool isValid(vector<pii> &dict, vector<pii> &revDict, const string &a, const string &b) {
	if(a.size() != b.size()) return false;
	bool good = true;
	for(int i=0; i<a.size(); i++) {
		int x=chg(a[i]),y=chg(b[i]);
		if(dict[x].second == 0 && revDict[y].second == 0) continue;
		else if(dict[x].second == 0) {
			if(revDict[y].first!=x) good=false;
		}
		else if(revDict[y].second == 0) {
			if(dict[x].first!=y) good=false;
		}
		else {
			if(dict[x].first!=y || revDict[y].first!=x) good = false;
		}

		if(!good) return false;
	}
	return true;
}
void dfs(int x, vector<pii> &dict, vector<pii> &revDict) {
	if(ans.size()>0) return;
	if(x == vList.size()) {
		ans = dict;
		return;
	}
	string s = vList[x];
	int len = s.size();

	for(int i=0; i<g[x].size(); i++) {
	//for(int i=0; i<w[len].size(); i++) {
		if(!isValid(dict, revDict, vList[x],wList[g[x][i]])) continue;
		regi(dict,revDict,vList[x],wList[g[x][i]]);
		dfs(x+1,dict,revDict);
		unregi(dict,revDict,vList[x],wList[g[x][i]]);
	}
}
vector<pii> dict,revDict;
int main() {
	freopen("input.txt","r",stdin);
	int n; cin >> n;
	string s;
	w.resize(17,vector<int>());
	for(int i=0; i<n; i++) {
		cin >> s;
		w[s.size()].emplace_back(i);
		wList.emplace_back(s);
	}

	string line;
	stringstream ss;
	while(getline(cin, line)) {
		if(line.size()==0) continue;

		vList.clear();
		ss.clear(); ss.str(line);
		while(getline(ss, s, ' ')) {
			if(s.size()==0) continue;
			vList.emplace_back(s);
		}

		g.clear(); g.resize(vList.size(),vector<int>());
		graphModeling();
		memset(chk,false,sizeof(chk));
		dict.clear(); dict.resize(26,pii(0,0));
		revDict.clear(); revDict.resize(26,pii(0,0));
		ans.clear();
		dfs(0,dict,revDict);
		if(ans.size()>0) {
			for(int i=0; i<line.size(); i++) {
				if(islower(line[i])) printf("%c",ans[line[i]-'a'].first+'a');
				else printf("%c",line[i]);
			}
			puts("");
		} else {
			for(int i=0; i<line.size(); i++) {
				if(islower(line[i])) printf("*");
				else printf("%c",line[i]);
			}
			puts("");
		}
	}
}
