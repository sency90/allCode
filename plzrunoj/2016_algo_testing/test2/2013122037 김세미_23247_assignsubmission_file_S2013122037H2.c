
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int n,m;        //n:처음 입력받는 크기, m:중복을 제거한 배열의 크기
    int tem[1000];  //처음 입력받는 배열
    int arr[1000];  //정렬 후 중복을 제거한 배열
    
    //초기 입력
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&tem[i]);
    
    //배열 정렬
    sort(tem,tem+n);
    
    arr[0] = tem[0];
    m = 0;
    
    //중복 원소 제거
    for(int i=0;i<n;i++)
    {
        if(arr[m] != tem[i]){
            arr[++m] = tem[i];
        }
    }
    
    //구하는 값 찾기
    for(int i = m; i >= 0; i--){
        if(m == 0){
            printf("%d\n",arr[i]);
            break;
        }
        if(arr[i] == m-i+1){
            printf("%d\n",arr[i]);
            break;
        }
    }

    return 0;
}
