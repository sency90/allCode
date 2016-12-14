#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
struct P {
    int no, age;
    char name[101];
};
struct P arr[100005];

bool sort1(const struct P &i, const struct P &j){
    if(i.age == j.age) return i.no<j.no;
    else return i.age < j.age;
}

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %s",&arr[i].age, arr[i].name);
        arr[i].no = i;
    }
    sort(arr,arr+N,sort1);
    for(int i=0; i<N; i++) {
        printf("%d %s\n",arr[i].age,arr[i].name);
    }
    return 0;
}
