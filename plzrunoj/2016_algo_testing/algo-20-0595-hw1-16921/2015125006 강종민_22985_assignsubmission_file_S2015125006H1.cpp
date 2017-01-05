#include <iostream>
#include <stdio.h>
using namespace std;

void Inorder(int Start, int End, int *tree_front, int *tree_back);

int main()
{
	int tree_front[1000] = { 0 };
	int tree_back[1000] = { 0 };
	int n;
	scanf("%d", &n);
	int Start = 0;
	int End = n-1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tree_front[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tree_back[i]);
	}
	Inorder(Start, End, tree_front, tree_back);
	for (int i = 0; i < n; i++)
	{
		cout << tree_front[i] << " ";
	}
	cout << endl;
	return 0;
}

void Inorder(int Start, int End, int *tree_front, int *tree_back)
{
	if (Start == End)
	{
		return;
	}
	int root = tree_front[Start];
	int finder = tree_front[Start + 1];
	int k;
	int i;
	k = 0;
	while (k < End)
	{
		if (tree_back[k] == finder)
		{
			break;
		}
		k++;
	}
	for ( i = Start; i < k + 1; i++)
	{
		tree_front[i] = tree_front[i + 1];
	}
	for ( i = End; i > k + 1; i--)
	{
		tree_back[i] = tree_back[i-1];
	}
	tree_front[k + 1] = root;
	tree_back[k+ 1] = root;
	Inorder(Start, k, tree_front, tree_back);
	Inorder(k+ 2, End, tree_front, tree_back);
	
}