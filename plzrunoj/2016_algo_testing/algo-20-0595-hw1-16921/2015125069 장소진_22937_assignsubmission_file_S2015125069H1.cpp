#include <iostream>
using namespace std;

int node_num;
int pre_search[50] = { 0, };
int post_search[50] = { 0, };

void search(int pr_start, int cnt, int post_start) {
	int i = 0;
	if (cnt <= 0) return;
	if (cnt == 1) {
		cout << pre_search[pr_start];
		return;
	}
	
	for (i = 0; i < node_num; i++) {
		if (post_search[i] == pre_search[pr_start+1]) {
			break;
		}
	}

	int temp = i-post_start+1;
	search(pr_start + 1, temp, post_start);
	cout << pre_search[pr_start];
	search(pr_start + temp + 1, cnt - temp - 1, post_start + temp );
}




int main() {
	cin >> node_num;
	for (int i = 0; i < node_num; i++) {
		cin >> pre_search[i];
	}
	for (int i = 0; i < node_num; i++) {
		cin >> post_search[i];
	}
	search(0, node_num, 0);
	cout << " ";
	return 0;
}