#include <fstream>
#include <cassert>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string inpre = "input_", outpre="output_", sfx=".txt", ifname, ofname, s;
ifstream in;
ofstream out;
namespace user{
	int n,k;
	string s;
	int d[26][100001];
	inline int calc(char x, char y) {
		int ret = (y-'a')-(x-'a');
		ret=(ret<0)?-ret:ret;
		return min(26-ret,ret);
	}
	bool judge(int x) {
		for(int i=0; i<26; i++) {
			for(int j=x; j<=n; j++) {
				if(d[i][j]-d[i][j-x]<=k) return true;
			}
		}
		return false;
	}
	int solve() {
        memset(d,0,sizeof(d));
		in>>n>>k>>s;
		for(int i=0; i<26; i++) {
			char base='a'+i;
			for(int j=0; j<n; j++) {
				d[i][j+1]=d[i][j]+calc(s[j],base);
			}
		}

		int lo=0, hi=s.size();
		while(lo<=hi) {
			int mid = (lo+hi)/2;
			if(judge(mid)) lo=mid+1;
			else hi=mid-1;
		}
		return lo-1;
	}
}

int main() {
    ios::sync_with_stdio(false);
    out = ofstream("output_total.txt");
    for(int i=10; i<=100; i++) {
        ifname=inpre+to_string(i)+sfx;
        //ofname=outpre+to_string(i)+sfx;

        in=ifstream(ifname);
        //out=ofstream(ofname);
        in.tie(0);
        out << user::solve() << "\n";
    }
    return 0;
}
