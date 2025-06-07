#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int search(int arr[], int x, int n)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

void printInOrder(int post[], int pre[], int in[], int n, int size)
{
	int root = search(post, pre[1], n);

	if (root != -1) {
		printInOrder(post, pre + 1, in, root + 1, size);
	}

	for (int i = 0; i < size; i++) {
		if (in[i] == pre[0]) {
			break;
		}
		if (in[i] == NULL) {
			in[i] = pre[0];
			break;
		}
	}
	
	if (root != -1) {
		printInOrder(post + root + 1, pre + root + 1, in, n - root - 1, size);
	}
}

int main()
{
	int size;
	scanf("%i", &size);

	int *pre = new int[size];
	int *post = new int[size];
	int *in = new int[size];

	for (int i = 0; i < size; i++) {
		scanf("%i", &pre[i]);
	}
	for (int i = 0; i < size; i++) {
		scanf("%i", &post[i]);
	}
	for (int i = 0; i < size; i++) {
		in[i] = NULL;
	}

	printInOrder(post, pre, in, size, size);

	for (int i = 0; i < size; i++) {
		printf("%i ", in[i]);
	}

	return 0;
}