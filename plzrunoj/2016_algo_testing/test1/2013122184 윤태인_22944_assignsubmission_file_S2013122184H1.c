#include <iostream>
void get_inorder(int *pre, int *post, int size);
int *cutting(int *arr, int start_index, int finish_index);
int count = 0;
int main()
{
	int size = 0;
	scanf_s("%d", &size);
	int *preorder = new int[size];
	int *postorder = new int[size];

	for (int i = 0; i < size; i++)
		scanf_s("%d", &preorder[i]);
	for (int i = 0; i < size; i++)
		scanf_s("%d", &postorder[i]);
	get_inorder(preorder, postorder, size);
	return 0;
	system("pause");
}
void get_inorder(int *pre, int *post,  int size)
{
	int root = pre[0];
	if (size == 1 ) {
		printf("%d ", root);
		count++;
		return;
	}
	pre = cutting(pre, 1, size - 1);
	post = cutting(post, 0, size - 2);
	int index = 0;
	int i = 0;
	for (i = 0; i < size - 1; i++){
		if (post[i] == pre[0]) {
			index = i;
			break;
		}
	}
	get_inorder(cutting(pre, 0, index), cutting(post, 0, index), index + 1);
	printf("%d ", root);
	if (size == 2 || size - 1 == index + 1)
		return;
	get_inorder(cutting(pre, index + 1, size - 1),cutting(post, index + 1, size - 1), size - 1 - (index + 1));
};
int *cutting(int *arr, int start_index, int finish_index) //배열 자르는 함수 start ~ finish 까지 잘라서 리턴 2,4 -> 2,3,4
{
	int new_size = finish_index - start_index + 1;
	int *temp = new int[new_size];
	for (int i = 0; i < new_size; i++)
	{
		temp[i] = arr[start_index + i];
	}
	arr = temp;
	return arr;
}