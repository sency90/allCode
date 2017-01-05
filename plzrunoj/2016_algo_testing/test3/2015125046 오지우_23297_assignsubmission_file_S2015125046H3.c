#include <iostream>
#include <cstdio>

using namespace std;

long long int DP[101][101][101];

int main()
{
   int aN, aL, aR;

   scanf("%d %d %d", &aN, &aL, &aR);

   DP[1][1][1] = 1;

   for (int n = 2; n <= aN; n++)
   {
      for (int l = 1; l <= aL; l++)
      {
         for (int r = 1; r <= aR; r++)
         {
            DP[n][l][r] = DP[n - 1][l - 1][r] + DP[n - 1][l][r - 1] + (DP[n - 1][l][r] * (n - 2));
            DP[n][l][r] %= 1000000007;
         }
      }
   }

   printf("%d", DP[aN][aL][aR]);
}
