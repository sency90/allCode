#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
//#define __DEBUG__
using namespace std;
char N[16], ans[51];
int d1,d2,c1,c2;
int main() {
    scanf("%s%d%d%d%d", N,&d1,&c1,&d2,&c2);
    int len = strlen(N);
    int f1=c1, f2=c2;
    for(int i=0; N[i]; i++) {
        if(N[i]-'0' == d1) f1--;
        else if(N[i]-'0' == d2) f2--;
    }
    if(f1<=0 && f2<=0) return 0&printf("%s\n", N);
    if(d1<d2) {
        swap(d1,d2);
        swap(c1,c2);
    }

    bool hasAns = false;
    int M=0;
#ifdef __DEUBG__
    printf("c1:%d, c2:%d, len:%d\n", c1,c2,len);
#endif
    bool isFirst = true;
    while(c1+c2 > len) {
        if(isFirst) {
            if(d2!=0 && c2>0) {
                c2--;
                ans[M++] = d2+'0';
            }
            else if(c1>0) {
                c1--;
                ans[M++] = d1+'0';
            }
        }
        else {
            if(c2>0) {
                c2--;
                ans[M++] = d2+'0';
            }
            else if(c1>0) {
                c1--;
                ans[M++] = d1+'0';
            }
        }
        isFirst = false;
    }
#ifdef __DEBUG__
    printf("M: %d\n", M);
#endif
    for(int i=0; i<len; i++) ans[i+M] = N[i];
    ans[len+M] = 0;

    for(int i=len-1; i>=0; i--) {
        int f1=c1, f2=c2;
        if(M==0) {
            for(int j=0; j<i; j++) {
                if(f1>0 && N[j]-'0'==d1) {
                    ans[j+M] = N[j];
                    f1--;
                }
                else if(f2>0 && N[j]-'0'==d2) {
                    ans[j+M] = N[j];
                    f2--;
                }
            }

            for(int j=N[i]-'0'+1; j<=9; j++) {
                if(f1>0 && j==d1) {
                    ans[i+M] = j+'0';
                    f1--;
                    break;
                }
                else if(f2>0 && j==d2) {
                    ans[i+M] = j+'0';
                    f2--;
                    break;
                }
            }
        }
        if(f1!=c1 || f2!=c2 || M>0) {
            for(int k=len-1; k>=i+1; k--) {
                if(f1>0) {
                    ans[k+M] = d1+'0';
                    f1--;
                }
                else if(f2>0) {
                    ans[k+M] = d2+'0';
                    f2--;
                }
                else {
                    ans[k+M] = '0';
                }
            }
            if(M>0) {
                if(f1>0) {
                    ans[i+M] = d1+'0';
                    f1--;
                }
                else if(f2>0) {
                    ans[i+M] = d2+'0';
                    f2--;
                }
            }
            if(f1<=0 && f2<=0) {
                hasAns = true;
                break;
            }
        }
    }

#ifdef __DEBUG__
    printf("M: %d\n", M);
    printf("preview-ans: %s\n", ans);
#endif

    if(hasAns) printf("%s", ans);
    else {
        for(int i=0; i<M; i++) ans[i+1]=ans[i];
        ans[len+(++M)]=0;

        for(int z=1; z<=9; z++) {
            int f1=c1,f2=c2;
            ans[0]=z+'0';
            if(f1>0 && z==d1) f1--;
            else if(f2>0 && z==d2) f2--;

            for(int i=len-1; i>=0; i--) {
                if(f1>0) {
                    ans[i+M] = d1+'0';
                    f1--;
                }
                else if(f2>0) {
                    ans[i+M] = d2+'0';
                    f2--;
                }
                else {
                    ans[i+M] = '0';
                }
            }
            if(f1<=0 && f2<=0) return 0&printf("%s", ans);
        }
    }
    return 0;
}
