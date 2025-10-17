#include<cstdio>
#define MAX 10000
using namespace std;

int n;
int res[MAX];
int maxResult = 0;
void swap(int* v, int* vv){
   int tmp = *v;
   *v = *vv;
   *vv = tmp;
}

void quickSort(int arr[], int left, int right){
   // terminate
   if(left > right) return;

   int mid = (left+right) / 2;
   int pivot = arr[mid];

   swap(&arr[mid], &arr[left]);

   int L = left+1;
   int R = right;

   while(1){
      while(arr[L] <= pivot){
         L++;
      }
      while(arr[R] > pivot){
         R--;
      }
      if(L>R) break;
      swap(&arr[L],&arr[R]);
   }
   swap(&arr[left], &arr[R]);
   quickSort(arr, left, R-1);
   quickSort(arr, R+1, right);
}
int main(){
   scanf("%d", &n);
   for(int i = 0 ; i < n ; i++){
      scanf("%d", &res[i]);
   } // SIZE N
   quickSort(res, 0, n-1);
   //for(int i = 0 ; i < n ; i++){
   //   printf("%d ", res[i]);
   //}printf("\nSORT\n");
   for(int i = 0 ; i < n ; i++){
      if(res[i] >= n-i ){ // 인용된 것 6 - 
         //printf("%d <= %d\n",res[i], n-i);
         maxResult = n-i;
         break;
      }
   }
   printf("%d\n", maxResult);
   return 0;
}