#include <stdio.h>
int Check(int *a,int n)
{
    int t = a[0];
    int i;
    int Ecount=0;
    int Scount=0;
    int sum = 0;

    for(i=0;i<3;i++)
    {
        if(a[i] == 60)
            Ecount++;
        sum += a[i];
    }
    if(Ecount == 3)
        return 0;
    if(sum == 180)
    {
        for(i=1;i<3;i++)
        {
            if(t == a[i])
                Scount++;
        }
        if(Scount == 1)
            return 3;
        else
            return 1;
    }
    else
        return 2;
}


int main()
{
    int a[3];
    int i;
    int result;
    for(i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
    }

    result = Check(a,3);
    if(result == 0)
        printf("Equilateral\n");
    else if(result == 3)
        printf("Isosceles\n");
    else if(result == 1)
        printf("Scalene\n");
    else
        printf("Error\n");

    return 0;
}
