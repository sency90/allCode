#include<iostream>
using namespace std;
long long bliding[101][101][101];
int main()
{
	int N,Left,Right;
	scanf("%d",&N);
	scanf("%d",&Left);
	scanf("%d",&Right);
	bliding[1][1][1] = 1;

	for(int n=2;n<= N;n++)
	{
		for(int l=1;l<=Left;l++)
		{
			for(int r=1;r <=Right;r++)
			{
				bliding[n][l][r] = bliding[n-1][l-1][r] + bliding[n-1][l][r-1] + bliding[n-1][l][r]*(n-2);
				bliding[n][l][r] %=1000000007;
			}
		}
	}
	cout<< bliding[N][Left][Right];
}
