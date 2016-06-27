#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[100001];
int d[100001];

int k;
int i;
int f(int n){
   d[n] = a[n];

   if (d[n] < d[n-1] + a[n])
      d[n] = d[n-1] + a[n];

   if(n<k)
      f(n+1);

   return a[n-1];
}

int main() {
   scanf("%d", &k);
   for(i = 1; i <= k; i++){
      scanf("%d", &a[i]);
   }

   f(1);
   int ans = -0x3f3f3f3f;
   for(i = 1; i <= k; i++){
      if(ans < d[i]){
          ans = d[i];
      }
   }

   printf("%d\n", ans);
   return 0;
}
