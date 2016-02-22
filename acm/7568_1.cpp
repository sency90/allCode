#include <stdio.h>
typedef struct People{
    int w;
    int h;
    int o;
}people;
people Class[51];

int main(){
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&Class[i].w,&Class[i].h);
        Class[i].o=N;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j){
                if(Class[i].w>=Class[j].w || Class[i].h>=Class[j].h)
                    Class[i].o=Class[i].o-1;
            }
        }
    }

    for(int i=0;i<N;i++){
        printf("%d ",Class[i].o);
    }

    return 0;
}
