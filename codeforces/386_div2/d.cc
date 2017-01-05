#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int k;
string mkstr(char c, int x) {
	if(x==0) return "";
	string ret = mkstr(c,x/2);
	if(x%2==1) return ret+ret+c;
	else return ret+ret;
}
void mkb(int &a, int &b, string &ans);
void mka(int &a, int &b, string &ans) {
	//printf("A: %d %d\n", a,b);
	if(a>=k) {
		a-=k;
		ans+=mkstr('G',k);
	} else {
		ans+=mkstr('G',a);
		a=0;
	}
	if(b!=0) mkb(a,b,ans);
}
void mkb(int &a, int &b, string &ans) {
	//printf("B: %d %d\n", a,b);
	if(b>=k) {
		b-=k;
		ans+=mkstr('B',k);
	} else {
		ans+=mkstr('B',b);
		b=0;
	}
	if(a!=0) mka(a,b,ans);
}
int main() {
	int n,a1,b1,a2,b2;
	scanf("%d%d%d%d",&n,&k,&a1,&b1);
	a2=a1; b2=b1;
	string ans1, ans2;
	mka(a1,b1,ans1);
	mkb(a2,b2,ans2);
	if(a1==0 && b1==0) return 0&printf("%s", ans1.c_str());
	else if(a2==0 && b2==0) return 0&printf("%s", ans2.c_str());
	else {
		string ta,tb;
		ta=mkstr('G',k);
		tb=mkstr('B',k);
		if(a1) {
			for(int i=0; i<ans1.size(); i++) {
				if(ans1[i]=='B'&&(ans1[i+1]=='B'||ans1[i+1]==0)) {
					if(k<=a1) {
						ans1=ans1.substr(0,i+1)+ta+ans1.substr(i+1,ans1.size());
						i+=k;
						a1-=k;
					} else {
						ans1=ans1.substr(0,i+1)+mkstr('G',a1)+ans1.substr(i+1,ans1.size());
						i+=a1;
						a1=0;
					}
				}
			}
			if(a1==0) return 0&printf("%s", ans1.c_str());
		} else if(b1) {
			for(int i=0; i<ans1.size(); i++) {
				if(ans1[i]=='G'&&(ans1[i+1]=='G'||ans1[i+1]==0)) {
					if(k<=b1) {
						ans1=ans1.substr(0,i+1)+tb+ans1.substr(i+1,ans1.size());
						i+=k;
						b1-=k;
					} else {
						ans1=ans1.substr(0,i+1)+mkstr('B',b1)+ans1.substr(i+1,ans1.size());
						i+=b1;
						b1=0;
					}
				}
			}
			if(b1==0) return 0&printf("%s", ans1.c_str());
		}
		if(a2) {
			for(int i=0; i<ans2.size(); i++) {
				if(ans2[i]=='B'&&(ans2[i+1]=='B'||ans2[i+1]==0)) {
					if(k<=a2) {
						ans2=ans2.substr(0,i+1)+ta+ans2.substr(i+1,ans2.size());
						i+=k;
						a2-=k;
					} else {
						ans2=ans2.substr(0,i+1)+mkstr('G',a2)+ans2.substr(i+1,ans2.size());
						i+=a2;
						a2=0;
					}
				}
			}
			if(a2==0) return 0&printf("%s", ans2.c_str());
		} else if(b2) {
			for(int i=0; i<ans2.size(); i++) {
				if(ans2[i]=='G'&&(ans2[i+1]=='G'||ans2[i+1]==0)) {
					if(k<=b2) {
						ans2=ans2.substr(0,i+1)+tb+ans2.substr(i+1,ans2.size());
						i+=k;
						b2-=k;
					} else {
						ans2=ans2.substr(0,i+1)+mkstr('B',b2)+ans2.substr(i+1,ans2.size());
						i+=b2;
						b2=0;
					}
				}
			}
			if(b2==0) return 0&printf("%s", ans2.c_str());
		}
		puts("NO");
	}
	return 0;
}
