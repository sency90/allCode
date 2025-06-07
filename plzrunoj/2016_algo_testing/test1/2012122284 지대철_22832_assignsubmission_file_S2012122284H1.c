#include<iostream>
using namespace std;

void Search(int* pre_order, int* post_order, int num) {
	int index = 0;

	for (int i = 0; i < num; i++)	if (pre_order[1] == post_order[i]) index = i;
	if (num == 1) {
		cout << post_order[0] << " ";
		return;
	}
	else if (num == 0) return;

	int* pre_left = new int[index + 1];
	int* pre_right = new int[num - (index + 1) - 1];
	int* post_left = new int[index + 1];
	int* post_right = new int[num - (index + 1) - 1];

	for (int i = 0; i < index + 1; i++) {
		pre_left[i] = pre_order[i + 1];
		post_left[i] = post_order[i];
	}
	for (int i = 0; i < num - index - 2; i++) {
		pre_right[i] = pre_order[index + i + 2];
		post_right[i] = post_order[index + i + 1];
	}

	Search(pre_left, post_left, index + 1);
	cout << pre_order[0] << " ";
	Search(pre_right, post_right, num - index - 2);
	return;
}

int main() {
	int count;
	cin >> count;
	int* pre_order = new int[count];
	int* post_order = new int[count];
	for (int i = 0; i < count; i++)	cin >> pre_order[i];
	for (int i = 0; i < count; i++)	cin >> post_order[i];
	Search(pre_order, post_order, count);
	system("pause");
	return 0;
}