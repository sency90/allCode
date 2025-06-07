#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const int &a, const int &b)
{
    return a > b;
}
int arr[1001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+n, comp);
    bool flag = false;
    for(int i=n-1;i>=0;i--){
        if(arr[i] >= i+1){
            printf("%d", i+1);
            flag = true;
            break;
        }
    }
    if(flag == false)
        printf("0\n");
    return 0;
}
