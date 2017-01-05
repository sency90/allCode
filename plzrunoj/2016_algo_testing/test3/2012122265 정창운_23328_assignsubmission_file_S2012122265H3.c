#include <iostream>

#define swap(a,b,temp) temp=a; a=b; b=temp;

int cnt1 = 1;
int cnt2 = 1;
int temp1, temp2;
int count = 0;

void permutations(int *a, const int k, const int m, int l, int r)
{
	int i;
	int temp;

	if (k == m)
	{
		temp1 = a[0];
		for (i = 0; i <= m; i++)
		{

			if (temp1 < a[i + 1]) {
				temp1 = a[i + 1];
				cnt1++;
			}
		}

		temp2 = a[m];
		for (i = m - 1; i >= 0; i--)
		{
			if (temp2 < a[i]) {
				temp2 = a[i];
				cnt2++;
			}
		}

		if (cnt1 == l && cnt2 == r) {
			count++;
		}

		cnt1 = 1;
		cnt2 = 1;
	}

	else
	{
		for (i = k; i <= m; i++)
		{
			swap(a[k], a[i], temp);
			permutations(a, k + 1, m, l, r);
			swap(a[k], a[i], temp);
		}
	}
}

int main()
{
	int n, l, r;
	int a[100];

	scanf("%d", &n);
	scanf("%d", &l);
	scanf("%d", &r);

	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}

	permutations(a, 0, n - 1, l, r);
	count %= 1000000007;
	printf("%d\n", count);
}