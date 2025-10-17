#include<iostream>
#include<cstdio>
using namespace std;

int pre[2000] = {0,} ;
int post[2000] = {0,} ;
bool isPrint[2000] = {0,};

int size = 0 ;
int temp, idx;

void in(int pre_s, int pre_e, int post_s, int post_e){


   int pre_R = pre[pre_s];
   int post_R = post[post_e];

   if(pre_e - pre_s <= 0 || post_e - post_s <= 0){
      if(!isPrint[post_e]){
         printf("%d ", post_R);
         isPrint[post_e] = !isPrint[post_e];
      }
      return ;
   }

   int post_left = 0;

   for(int i = post_s ; i <= post_e ; i++){
      if(post[i] == pre[pre_s + 1]){
         post_left = i;
      }
   }

   int left = post_left - post_s ;

   in( pre_s + 1 , pre_s + 1 + left , post_s , post_left);//,count+1);
   if(!isPrint[post_e]){
      printf("%d ", post_R);
      isPrint[post_e] = !isPrint[post_e];
   }   
   in( pre_s + left + 2 , pre_e , post_left + 1 , post_e-1);//,count+1);
}

void calculateInorder(){
   cin >> size;
   for(int i = 0, idx = -1 ; i < size ; i++) cin >> pre[++idx];      
   for(int i = 0, idx = -1 ; i < size ; i++) cin >> post[++idx];   

   in(0,size-1,0,size-1);//,0);
   printf("\n");

}
int quit = 1;
int main(){
  
   calculateInorder();
  
   return 0;

}