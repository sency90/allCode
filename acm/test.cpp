#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num_len(int num)
{
    int k = 1;

    if (num / 10 == 0)
        return k;
    while (num / 10 != 0)
    {
        num = num / 10;
        k++;
    }
    return k;
}
int trans(int num)
{
    int ret = 0;
    int len = num_len(num);
    for (int i = len - 1; i >= 0; i--)
    {
        int x = pow(10, i);
        if (9 - num / x == 0)
            continue;
        else
            ret =ret + (9 - num / x)*x;
        num = num%x;
    }
    return ret;
}


int main(void)
{
    //freopen("input.txt", "r", stdin);
    int t_case;
    int x;
    scanf("%d", &t_case);
    while (t_case--)
    {
        int big = 0;
        int len;
        double a;
        int temp;
        scanf("%d", &x);
        len=num_len(x);
        a = pow(10, len);
        temp = a / 2;
        if (temp >= x)
            printf("%d\n", x*trans(x));
        else
            printf("%d\n", temp*trans(temp));

    }
}
