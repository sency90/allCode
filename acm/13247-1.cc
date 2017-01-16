#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
int popcount(int x) {
	int ans = 0;
	while (x > 0) {
		ans += x&1;
		x >>= 1;
	}
	return ans;
}
int check(string &s, int state) {
	vector<pair<int,int>> rabbit;
	int n = s.length();
	for (int i=0; i<n; i++) {
		if (state & (1<<i)) {
			rabbit.push_back(make_pair(i,-1));
		}
	}
	while (n > 2) {
		vector<pair<int,int>> next;
		for (int i=0; i<rabbit.size(); i++) {
			int now = rabbit[i].first;
			int prev = rabbit[i].second;
			if (now == 0) {
				next.push_back(make_pair(now+1, now));
			} else if (now == n-1 || now == n-2) {
				next.push_back(make_pair(now-1, now));
			} else {
				if (s[now] == 'W') {
					next.push_back(make_pair(now-1, now));
				} else if (s[now] == 'B') {
					next.push_back(make_pair(now+1, now));
				} else {
					if (prev == -1) {
						next.push_back(make_pair(now-1, now));
					} else {
						next.push_back(make_pair(prev, now));
					}
				}
			}
		}
		vector<int> cnt(n);
		for (int i=0; i<next.size(); i++) {
			cnt[next[i].first] += 1;
		}
		rabbit.clear();
		for (int i=0; i<next.size(); i++) {
			if (cnt[next[i].first] == 1) {
				rabbit.push_back(next[i]);
			}
		}
		n -= 1;
	}
	return (int)rabbit.size();
}
int main() {
	string s;
	cin >> s;
	int r;
	cin >> r;
	int bj=0;
	int bm=0;
	int n = s.length();
	for (int i=0; i<(1<<n); i++) {
		if (popcount(i) == r) {
			bm += 1;
			bj += check(s, i);
		}
	}
    cout <<"bj: "<< bj << "\n";
    cout <<"bm: "<< bm << "\n";
	cout << fixed << setprecision(10) << (double)bj/bm << '\n';
	return 0;
}
