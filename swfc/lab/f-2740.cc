#include <stdio.h>

int N;//마을수

int pos[100000+10];//마을위치

int fish[100000+10];//물고기양

int check(int m){

             long long need = 0, temp;

             int i;

             for(i=0;i<N-1;i++){

                           temp = fish[i] + need;

                           if(temp < m){//부족하므로무조건이웃마을에서가져옴

                                        need = temp - m - (pos[i+1] - pos[i]);//필요양과세금만큼을이웃마을에서가져오기

                           }

                           else{//남는경우

                                        need = temp - m - (pos[i+1] - pos[i]);//남은양을이웃마을로보내기

                                        if(need < 0) need = 0;//이웃마을로보내는세금이많아서음수가되는경우에는보내지않음

                           }

             }

             if(fish[N-1]+need >= m) return 1;//가능

             return 0;//불가능

}

int solve(int e){

             int s=0, m, sol=0;

             while(s<=e){

                           m = (s+e)/2;

                           if(check(m) == 1){

                                        s = m+1; sol = m;

                           }

                           else e = m-1;

             }

             return sol;

}

int main(void){

             int i, ans, max=0;

             scanf("%d", &N);

             for(i=0;i<N;i++){

                           scanf("%d %d", &pos[i], &fish[i]);

                          if(max < fish[i]) max = fish[i];

             }

             ans = solve(max);

             printf("%d\n", ans);

             return 0;

}
