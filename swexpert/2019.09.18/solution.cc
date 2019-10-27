#include <cstdio>
using namespace std;
unsigned char key[200];
extern int check(unsigned char *key);
bool judge(int mid, int val, unsigned char *key) {
    for(int i=0; i<=mid; i++) key[i] = val;
    for(int i=mid+1; i<200; i++) key[i] = 0;

    return (check(key)>>8);
}
int hubo[200];
bool unvalid[256];
int ansPos[256];
void test(unsigned char *key) {
    //init
    for(int i=0; i<256; i++) unvalid[i] = false;

    for(int i=1; i<256; i++) {
        for(int pos=0; pos<200; pos++) key[pos] = i;
        if(check(key) == 0) unvalid[i] = true;
    }

    int idx=0;
    for(int i=0; i<256; i++) {
        if(!unvalid[i]) hubo[idx++] = i;
    }

    for(int i=0; i<idx; i++) {
        int lo=0, hi=198;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(judge(mid, hubo[i], key)) hi=mid-1;
            else lo=mid+1;
        }

        ansPos[hubo[i]] = hi+1;
    }

    for(int i=0; i<idx; i++) {
        key[ansPos[hubo[i]]] = hubo[i];
    }
}
int main() {
    test(key);
    return 0;
}
