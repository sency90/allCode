#include <stdio.h>
typedef long long ll;
int len;
char str[202];
const ll BASE = 10LL;
int strlen(const char * s) {
	int ret = 0;
	while(s[ret]) ret++;
	return ret;
}
inline bool isdigit(char c) { 
	return '0'<=c && c<='9';
}
inline ll mkdigit(int & idx) {
	ll ret = 0LL;
	while(isdigit(str[idx])) {
		ret *= BASE;
		ret += (str[idx++]-'0');
	}
	return ret;
}
//ex = term {'+'|'-', term}
ll ex(int &);
ll term(int &);
ll factor(int &);
ll ex(int & idx) {
	ll ret = term(idx);
	while(idx<len) {
		char sym = str[idx];
		if(sym == '+') ret += term(++idx);
		else if(sym == '-') ret -= term(++idx);
		else return ret;
	}
	return ret;
}
//term = factor {'*'|'/', factor}
ll term(int & idx) {
	ll ret = factor(idx);
	while(idx<len) {
		char sym = str[idx];
		if(sym == '*') ret *= factor(++idx);
		else if(sym == '/') ret /= factor(++idx);
		else return ret;
	}
	return ret;
}
//factor = (['+'|'-'], digit) | ( '(', ex, ')' )
ll factor(int & idx) {
	ll ret = 0;
	if(str[idx]=='+') ret = mkdigit(++idx);
	else if(str[idx]=='-') ret = -mkdigit(++idx);
	else if(isdigit(str[idx])) ret = mkdigit(idx);
	else if(str[idx] == '(') {
		ret = ex(++idx);
		idx++;
	}
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%s", str);
	len = strlen(str);
	int idx = 0;
	printf("%lld\n", ex(idx));
	return 0;
}
