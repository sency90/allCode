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
      //�Է¹��� �� ���� ����ŭ �����Ҵ�
      arr = (int*)malloc(sizeof(int*)*node_num); 
      count_arr = (int*)malloc(sizeof(int*)*node_num);

        //����ڷκ��� ���� ����ŭ �Է¹���
         for(i=0; i< node_num; i++){

            scanf("%d", &arr[i]);
         }
         //�ش� �ε������� ū ���Ұ� ����� ī��Ʈ�ϱ����� �ݺ���
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
      
   
          //������ �����ϴ� ���߿� �ִ� ���� ã������ �ݺ���
         for(i=0; i < node_num; i++){
            
                if(arr[i]<= count_arr[i]){
                   if(max<arr[i]){

                   max = arr[i];

                   }   
                }
         }
         printf("%d\n", max);
         //�����Ҵ� ����
         free(arr);
         free(count_arr);

   }

