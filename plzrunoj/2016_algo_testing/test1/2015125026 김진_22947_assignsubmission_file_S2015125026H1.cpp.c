#include <iostream>

using namespace std;


void tra(int *left, int *right, int n, int part)
{
	int partition = part;

	for (int i = 0; i < n; i++) {
		if (left[1] == right[i]){
			partition = i; 
			break; 
		}
	}

	if (n == 1 || n == 0) {

		if (n == 1) {
			cout << right[0] << " ";
			return;
		}
		else {
			return;
		}
	}

	int *lleft = new int[partition + 1];
	int *rleft = new int[n - partition - 2];


	int *lright = new int[partition + 1];
	int *rright = new int[n - partition - 2];

	for (int i = 0; i < partition + 1; i++)
	{
		lleft[i] = left[i + 1];
		lright[i] = right[i];
	}
	for (int i = 0; i < n - partition - 2; i++)
	{
		rleft[i] = left[partition + i + 2];
		rright[i] = right[partition + i + 1];
	}

	tra(lleft, lright, partition + 1,0);
	cout << left[0] << " ";
	tra(rleft, rright, n - partition - 2,0);
	return;
}
int main()
{
	int n;
	cin >> n;
	int *left = new int[n];
	int *right = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> left[i];
	}for (int i = 0; i < n; i++) {
		cin >> right[i];
	}
	tra(left, right, n, 0);
}