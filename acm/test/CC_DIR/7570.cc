#include <stdio.h>
int a[1000001];
int idx[1000002];
int main() {
    int n, max=0, s;
    scanf("%d",&n);
    int i,j,k;
    for(i=0; i<n; i++) {
            scanf("%d",a+i);
            idx[a[i]]=i;
        }
        idx[n+1]=0;
            //a={5,2,4,1,3}
            //    //idx={3,1,4,2,0}
            //        //s = 0
            //            for(i=0; i<n; i++) {
            //                    s = idx[a[i]];
            //                            //즉, a[i]보다 뒤에 있는 숫자라면 그 idx값을 s에 저장. -> 그럼 마지막에 맨 뒤에 있던 idx값인 2가 들어가게 됨
            //                                    printf("idx[j]: ");
            //                                            for(j=a[i]+1; s < idx[j]; j++) {
            //                                                        printf("%d ", idx[j]);
            //                                                                }
            //                                                                        puts("");
            //                                                                                printf("s: %d, ", s);
            //
            //                                                                                        printf("j-a[i]: %d\n", j-a[i]);
            //                                                                                                max = max < j-a[i]? j-a[i]:max;
            //                                                                                                    }
            //                                                                                                        printf("%d",n-max);
            //                                                                                                        }
            //                                                                                                        ]]]>)}
