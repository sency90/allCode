#include<stdio.h>
#include<stdlib.h>
int main(){
    int a ;// 실행 횟수
    int b , c;// 건물 갯수 , 건물 건설 규칙 갯수
    int e , f;// 몇번 건물에서 몇번으로 가는지 
    int build[1000]; // 각 건물 짓는데 걸리는 시간 -> 자신혼자 걸리는 시간
    int maxbuild[100000]={0}; // 각 건물을 짓는데 걸리는 총 시간 
    int temp;
    scanf("%d",&a);
    for(int x = 0 ; x < a ; x++)
    {
        scanf("%d %d ",&b,&c);// 건물 갯수와 건물 규칙 
        for ( int i = 0; i < b ; i++){
            scanf("%d",&build[i]); 
        }
        maxbuild[0] = build[0];
        for ( int i = 0 ; i < c ; i++){
            scanf("%d %d",&e,&f);
            temp = maxbuild[e-1] + build[f-1];   // 앞 경로 까지의 합과 비교하여 더 오래걸리는 시간만을 저장 
            if(maxbuild[f-1] < temp){
                maxbuild[f-1] = temp;
            }
        }
        scanf("%d",&temp);
        if(maxbuild[temp-1] ==0){   // 출력점이 시작점인 경우 
            maxbuild[temp-1]=build[temp-1];
        }
        printf("%d\n",maxbuild[temp-1]);
        for ( int i = 0; i < b ; i++){
            maxbuild[i]=0;
            build[i]=0;
        }
    }
}
