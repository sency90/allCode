#include <iostream>
using namespace std;
int get_answer(int *data, int *pick, int size);
void bubblesort(int *data, int *pick, int data_size);
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int *data = new int[n];
	int *pick = new int[n];
	for (int i = 0; i < n; i++)
		scanf_s("%d", &data[i]);
	int answer = get_answer(data, pick, n);
	printf("%d ", answer);
	system("pause");
	return 0;
}
int get_answer(int *data, int *pick, int size)
{
	int answer_index = 0;
	bubblesort(data, pick, size);
	for (int i = 0; i < size; i++)
	{
		if (data[i] >= size - i) {
			pick[i] = 1;
		}
	}
	for (int i = size - 1; i >= 0; i--) {
		if (pick[i] == 1) {
			answer_index = i;
		}
	}
	return data[answer_index];
}
void bubblesort(int *data, int*pick, int data_size)
{
	int temp = 0;
	for (int i = 0; i < data_size - 1; i++){
		pick[i] = 0;
		for (int j = 0; j < data_size - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
	}
}