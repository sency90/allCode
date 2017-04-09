#include <stdio.h>
#define DIGIT 311
int main() {
    for(long long i=2; i*i<DIGIT; i++) {
        if(DIGIT%i==0) {
            printf("%lld", i);
            return 0;
        }
    }
}
