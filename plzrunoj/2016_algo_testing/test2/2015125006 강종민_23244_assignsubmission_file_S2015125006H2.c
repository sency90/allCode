#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
int main()
{
	int n;
	int count=0;
	scanf("%d", &n);
	list<int> l;
	for (int i = 0; i < n; i++)
	{
		int Input;
		scanf("%d", &Input);
		l.push_back(Input);
	}
	l.sort();
	for (list<int>::reverse_iterator iter = l.rbegin(); iter != l.rend(); iter++) {
		count = 0;
		for (list<int>::reverse_iterator iter1 = l.rbegin(); iter1 != l.rend(); iter1++)
		{
			if (*iter <= *iter1)
			{
				count++;
			}
		}
		if (count >= *iter)
		{
			cout << *iter;
			break;
		}
	}
	cout << endl;
	return 0;
}