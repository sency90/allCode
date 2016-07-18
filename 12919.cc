#include<stdio.h>
#include<string>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
queue<pair<string, int> > q;
int main() {
	string a, b;
	cin >> a >> b;
	int l = a.length();
	q.push(make_pair(b, b.size()));
	while (!q.empty()) {
		string x = q.front().first;
		int x_l = q.front().second;
		if (l == x_l + 1) break;
		if (l == x_l) {
			if (x == a) {
				printf("1");
				return 0;
			}
			else {
				q.pop();
				continue;
			}
		}
		q.pop();
		if (x.back() == 'A') {
			string temp = x;
			temp.pop_back();
			q.push(make_pair(temp, x_l - 1));
		}
		if (x[0] == 'B') {
			string temp;
			int temp_l = x_l;
			while (x_l != 1) {
				temp.push_back(x.back());
				x.pop_back();
				x_l--;
			}
			q.push(make_pair(temp, temp_l - 1));
		}
	}
	printf("0");
}
