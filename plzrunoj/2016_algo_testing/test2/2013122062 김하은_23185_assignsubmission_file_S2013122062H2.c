#include<stdio.h>
#include<stdlib.h>

void main(){

   int i,j;
   int cnt;
   int trial_num=0;
   int node_num =0;
   int element =0;
   int *arr;
   int *count_arr;
   int max;



      scanf("%d", &node_num);
      max=0;
      cnt=0;
      //입력받을 총 원소 수만큼 동적할당
      arr = (int*)malloc(sizeof(int*)*node_num); 
      count_arr = (int*)malloc(sizeof(int*)*node_num);

        //사용자로부터 원소 수만큼 입력받음
         for(i=0; i< node_num; i++){

            scanf("%d", &arr[i]);
         }
         //해당 인덱스보다 큰 원소가 몇개인지 카운트하기위한 반복문
         for(i=0; i< node_num; i++){

            element = arr[i];
            cnt =0;
            for(j=0; j< node_num; j++){

               if(element <= arr[j]){
                  cnt++;
                  //printf("cnt : %d", cnt);
               }               
               
            }
            count_arr[i] = cnt;
            
         }
      
   
          //조건을 만족하는 수중에 최대 값을 찾기위한 반복문
         for(i=0; i < node_num; i++){
            
                if(arr[i]<= count_arr[i]){
                   if(max<arr[i]){

                   max = arr[i];

                   }   
                }
         }
         printf("%d\n", max);
         //동적할당 해제
         free(arr);
         free(count_arr);

   }

