#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <stack>
using namespace std;
struct AncientLanguage{
	string s;
	vector<int> adj[3000];
	int vis[3001]={0,};
	int A[3001],B[3001];
	map<string,int> m;
	int st,ed;

	int Id(char a,char b){
		string temp;
		temp+=a;
		temp+=b;
		return m[temp];
	}

	bool dfs(int here){
		if(vis[here])return false;
		vis[here]=1;
		for(auto there:adj[here]){
			if(B[there]==-1 || dfs(there)){
				A[here]=there;
				B[there]=here;
				return true;
			}
		}
		return false;
	}

	int minWords(vector<string> t){
		for(int i=0;i<t.size();i++)
			s+=t[i];
		memset(A,-1,sizeof(A));
		memset(B,-1,sizeof(B));
		int ans=0;
		int cnt=1;
		for(int i=0;i<s.length()-1;i++){
			string temp=s.substr(i,2);
			if(m.count(temp))continue;
			m[temp];
			//m[temp]=cnt++;
		}
		for(auto it=m.begin();it!=m.end();it++){
			it->second=cnt++;
		}
		for(auto it=m.begin();it!=m.end();it++){
			cout<<it->first<<' '<<it->second<<endl;
		}
		st=Id(s[0],s[1]); ed=Id(s[s.length()-2],s[s.length()-1]);
		adj[st].push_back(st);
		if(st!=ed)adj[ed].push_back(ed);
		for(int i=1;i<s.length()-1;i++){
			int u=m[s.substr(i-1,2)];
			int v=m[s.substr(i,2)];
			if(i&1)adj[u].push_back(v);
			else adj[v].push_back(u);
		}
		for(int i=1;i<=cnt-1;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i))ans++;
		}
		return ans;
	}
};

int main(){
	AncientLanguage A;
	cout<<A.minWords({{"RpNuNqSlAmAqArHhSdCiAtJbAjUeUqIuEhP", "rMrQlEpQjSrFnHj", "RrQjRkRbObMpGlBeAhEjBiUhOjFbJeTsKmUeK", "kSoRrHcGeRoRhO", "pSrQeI", "n", "A", "o", "Q", "r", "K", "c", "K", "c", "P", "o", "M", "h", "M", "s", "H", "d", "B", "l", "R", "d", "U", "n", "Q", "t", "E", "u", "B", "k", "P", "m", "P", "b", "F", "j", "S", "h", "S", "q", "N", "e", "S", "b", "C", "i"}});
}
