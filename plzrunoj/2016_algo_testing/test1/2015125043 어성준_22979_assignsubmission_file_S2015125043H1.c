#include<iostream>
using namespace std;
/*
        7
  11         20
1   12    17   23

노드 수 : 7
전위 : 7 11 1 12 20 17 23
후위 : 1 12 11 17 23 20 7
중위 : 1 11 12 7 17 20 23
*/
long PreOrder[1000][2] = {}; //전위순회
long PostOrder[1000] = {}; //후위순회
long InOrder[1000] = {}; //중위순회
long temp[1000][2] = {};

void TempState(long L);
void PreOrderState(long L);
bool InOrder_TempState(long L);

int main()
{
	while (true)
	{
		int nodeNum; // 노드 갯수
		int k = 0, n = 1;
		long Stack[1000] = {};
		cout << "우선 노드의 갯수를 입력하세요 : ";
		cin >> nodeNum;

		if (nodeNum >= 1 && nodeNum <= 1000)
		{
			cout << "전위순회 순서 입력 : " << endl;
			for (int i = 0; i < nodeNum; i++)
			{
				cin >> PreOrder[i][0];
			}

			cout << "후위순회 순서 입력 : " << endl;
			for (int i = 0; i < nodeNum; i++)
			{
				cin >> PostOrder[i];
			}

			for (int i = 0; i < nodeNum; i++)
			{
				for (int j = 0; j < nodeNum; j++)
				{
					if (PreOrder[i][0] != PostOrder[j])
						temp[j][0] = PostOrder[j];
					else if (PreOrder[i][0] == PostOrder[j])
					{
						Stack[n+1] = PreOrder[i][0];
						n += 1;
						TempState(n);
						if (temp[0][0] == 0 || InOrder_TempState(n))
						{
							InOrder[k] = Stack[n];
							k += 1;
							n -= 1;
							InOrder[k] = Stack[n];
							k += 1;
							n -= 1;
						}
						int i = 0;
						while (i < nodeNum)
						{
							temp[i][0] = 0;
							temp[i][1] = 0;
							i++;
						}
						break;
					}
				}
			}
			PreOrderState(nodeNum);
			cout << "**중위순회 결과 : ";
			for (int i = 0; i < nodeNum; i++) {
				cout << InOrder[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "노드 수를 정의할 수 없거나 너무 많습니다" << endl;
		}
	}
	system("pause");
}
//------------------------------------------------------------
//------------------------------------------------------------
void TempState(long L)
{
	for (int i = 0; i<L; i++)
	{
		for (int j = 0; j<L; j++)
		{
			if (temp[i][0] == InOrder[j])
			{
				temp[i][1] = 1;
			}
		}
	}
}

void PreOrderState(long L)
{
	for (int i = 0; i<L; i++)
	{
		for (int j = 0; j<L; j++)
		{
			if (PreOrder[i][0] == InOrder[j])
			{
				PreOrder[i][1] = 1;
			}
		}
	}
	for (int i = 0; i<L; i++)
		if (PreOrder[i][1] == 0) InOrder[L - 1] = PreOrder[i][0];
}

bool InOrder_TempState(long L)
{
	if (L == 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i<L; i++)
		{
			if (temp[i][1] != 1)
			{
				return false;
			}
		}
	}
	return true;
}