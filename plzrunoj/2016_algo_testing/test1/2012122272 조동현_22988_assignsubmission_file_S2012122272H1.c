#include <iostream>
using namespace std;

void in(int a, int b, int *c, int *d)
{
	int *l, *r;
	int i = 0;
	while (i < b)
	{
		if (d[i] == a)
		{
			i++;
			break;
		}
		i++;
	}
	l = new int[i];
	r = new int[i];
	int j = 0;
	while (j < i)
	{
		l[j] = c[j + 1];
		r[j] = d[j];
		j++;
	}
	if (j == 1)   cout << l[0] << " ";
	else in(l[1], i, l, r);
	cout << c[0] << " ";
	if ((b - i - 1) == 0) return;
	l = new int[b - i - 1];
	r = new int[b - i - 1];
	int t = i;
	while (i < b - 1)
	{
		l[i - t] = c[i + 1];
		r[i - t] = d[i];
		i++;
	}
	if (i == t + 1) cout << l[0] << " ";
	else in(l[1], b - t - 1, l, r);
}
int main()
{
	int b = 0;
	int *c, *d;
	int i = 0, j = 0;

	while (b > 1000 || b < 1)
	{
		cout << "갯수" << endl;
		cin >> b;
	}

	c = new int[b];
	d = new int[b];

	cout << "전위 순회" << endl;
	while (i < b)
	{
		cin >> c[i++];
	}

	cout << "후위 순회" << endl;
	i = 0;
	while (i < b)
	{
		cin >> d[i++];
	}

	in(c[1], b, c, d);

	return 0;
}