#include <iostream>
#include <algorithm>

using namespace std;

pair <int, int> postOrder[1000];
int preOrder[1000];
int node;
void Getinorder(int preOrderStart, int postOrderStart, int size)
{
	if (size == 0) return;
	if (size == 1){ cout << preOrder[preOrderStart] << " "; return; }
	int rootIndex = preOrderStart;
	int leftsize = lower_bound(postOrder, postOrder + node, make_pair(preOrder[rootIndex + 1],0))->second - postOrderStart + 1;
	Getinorder(preOrderStart + 1, postOrderStart, leftsize);
	cout << preOrder[rootIndex] << " ";
	Getinorder(preOrderStart + leftsize + 1, postOrderStart + leftsize, size - leftsize - 1);
}
int main()
{
	cin >> node;
	for (int i = 0; i < node; i++) cin >> preOrder[i];
	for (int i = 0; i < node; i++)
	{
		int input;
		cin >> input;
		postOrder[i] = make_pair(input, i);
	}
	sort(postOrder, postOrder + node);
	Getinorder(0, 0, node);
}