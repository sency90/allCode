#include <stdio.h>
 
int building_arr[101][101][101];
 
int main()
{
    int num_of_build;
   int left;
   int right;
   int i, j, k;
   int div = 1000000007;
   long long int temp;
 
    scanf("%d %d %d", &num_of_build, &left, &right);
   
    building_arr[1][1][1] = 1;
    building_arr[2][1][2] = 1;
   building_arr[2][2][1] = 1;
 
    for (i = 3; i < num_of_build+1; i++) {
        building_arr[i][i][1] = building_arr[i][1][i] = 1;
        for (j = 1; j < num_of_build+1; j++) {
            for (k = 1; k < num_of_build+1; k++) {
                temp = building_arr[i - 1][j][k];
                temp = (temp * (i - 2)) ;
                temp = (temp + building_arr[i - 1][j - 1][k]) ;
                temp = (temp + building_arr[i - 1][j][k - 1]) ;
 
                building_arr[i][j][k] = temp % div;
            }
        }
    }
 
    printf("%d\n", building_arr[num_of_build][left][right]);
 
    return 0;
}