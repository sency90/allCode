#include <iostream>
#include <string>
#define MAXN 200
using namespace std;
string ABS(string &x) {
	if(x[0]=='-') return x.substr(1);
	else if(x[0]=='+') return x.substr(1);
	else return x;
}
int cmp(const string &x,const string &y) {
	int xl=x.size(),yl=y.size();
	if(xl==yl) {
		for(int i=0; i<xl; i++) {
			if(x[i]<y[i]) return -1;
			else if(x[i]>y[i]) return 1;
		}
		return 0;
	} else if(xl<yl) return -1;
	else return 1;
}
int cmp(const string &x,const string &y,int s, int e) {
	if(e-s+1 == y.size()) {
		for(int i=s,j=0; i<=e; i++,j++) {
			if(x[i]<y[j]) return -1;
			else if(x[i]>y[j]) return 1;
		}
		return 0;
	} else if(e-s+1 < y.size()) return -1;
	else return 1;
}
int a[MAXN+1],b[MAXN+1];
string subtract(string &x,string &y,int s, int e) {
	int as=0,bs=0;
	register int i,j;

	for(i=e,j=MAXN; i>=s; i--,j--) a[j]=x[i]-'0';
	as=j+1;
	for(;j>=0; j--) a[j]=0;

	for(i=y.size()-1,j=MAXN; i>=0; i--,j--) b[j]=y[i]-'0';
	bs=j+1;
	for(;j>=0; j--) b[j]=0;

	for(int i=as+1; i<=MAXN; i++) a[i]+=10, a[i-1]--;
	for(int i=as; i<=MAXN; i++) a[i]-=b[i];
	for(int i=MAXN; i>=as; i--) {
		if(a[i]>=10) a[i]-=10,a[i-1]++;
	}

	string ret;
	for(int i=as; i<=MAXN; i++) ret+=a[i]+'0';
	return ret;
}

void zip(string &s) {
	int mem=s.size();
	for(int i=0; i<s.size(); i++) {
		if(s[i]!='0') {
			mem=i;
			break;
		}
	}
	if(mem==s.size()) s="0";
	else {
		string t;
		for(int i=mem; i<s.size(); i++) t+=s[i];
		s=t;
	}
}

string ans;
void div(string &x,string &y) {
	string nx=ABS(x),ny=ABS(y);
	ans=x;
	for(int i=0; i<ans.size(); i++) ans[i]='0';
	bool xp=(x[0]=='-')?false:true, yp=(y[0]=='-')?false:true;

	int nxl=nx.size(),nyl=ny.size();

	int s=0,e=ny.size()-1;
	while(e<nx.size()) {
		while(e<nx.size() && cmp(nx,ny,s,e)<0) e++;

		int cnt=0;
		while(e<nx.size() && cmp(nx,ny,s,e)>=0) {
			string r=subtract(nx,ny,s,e);
			cnt++;
			for(int i=s,j=0; i<=e; i++,j++) nx[i]=r[j];
			int mem=e;
			for(int i=s; i<=e; i++) {
				if(nx[i]!='0') {
					mem=i; break;
				}
			}
			s=mem;
		}
		ans[e]=cnt+'0';
		e++;
		if(e>=nx.size()) break;
		while(nx[s]=='0' && e<nx.size()) {
			if(s<e) s++,e=s+ny.size()-1;
		}
	}
	zip(ans);
	printf("%s\n",ans.c_str());
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string x,y;
	while(true) {
		cin >> x >> y;
		if(x=="0" && y=="0") return 0;

		int cmpres = cmp(ABS(x),ABS(y));
		if(cmpres==0) puts("1");
		else {
			if(cmpres<0) swap(x,y);
			div(x,y);
		}
	}
	return 0;
}
