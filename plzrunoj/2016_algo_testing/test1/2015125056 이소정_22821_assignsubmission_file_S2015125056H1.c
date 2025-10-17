#include<iostream>
using namespace std;
int m = 0;
int k = 0;

void findRoot(int *pre, int *in, int *post, int nodenum)
{
	if (*pre == 0) return;

	int root = pre[0];
	int *preleft = new int[nodenum];
	int *preright = new int[nodenum];
	int *postleft = new int[nodenum];
	int *postright = new int[nodenum];

	if (nodenum == 1)
	{
		*(in + m) = *(pre + 0);

		m++;

		return;
	}

	for (int i = 0; i < nodenum; i++)
	{

		if (*(pre + 1) == *(post + i))
		{

			for (int j = 0; j < i + 1; j++)
			{
				*(postleft + k) = *(post + j);
				k++;
			}
			k = 0;
			for (int j = i + 1; j < nodenum - 1; j++)
			{
				*(postright + k) = *(post + j);
				k++;
			}
			k = 0;
			for (int j = 1; j < i + 2; j++)
			{
				*(preleft + k) = *(pre + j);
				k++;
			}
			k = 0;
			for (int j = i + 2; j < nodenum; j++)
			{
				*(preright + k) = *(pre + j);
				k++;
			}
			k = 0;

			findRoot(preleft, in, postleft, i + 1);
			*(in + m) = root;
			m++;
			findRoot(preright, in, postright, nodenum - 2 - i);

		}
	}
}

//메인
void main()
{
	int nodenum;
	int *pre = new int;
	int *in = new int;
	int *post = new int;

	cin >> nodenum;
	if (nodenum < 1 || nodenum>1000)
	{
		cout << "범위wrong";
		system("pause");
	}
	//cout << "\n";
	pre = new int[nodenum];
	post = new int[nodenum];
	in = new int[nodenum];
	for (int j = 0; j<nodenum; j++)
	{
		cin >> *(pre + j);
	}
	cout << "\n";
	for (int j = 0; j<nodenum; j++)
	{
		cin >> *(post + j);
	}
	cout << "\n";
	findRoot(pre, in, post, nodenum);

	for (int j = 0; j<nodenum; j++)
	{
		cout << in[j] << " ";
	}
	cout << "\n";


	system("pause");

}