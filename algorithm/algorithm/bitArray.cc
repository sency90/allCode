#include <stdio.h>
typedef unsigned long long uint64;
int get(uint64 mask, int index) {
    return (mask >> (index << 2)) & 15;
}
uint64 set(uint64 mask, int index, uint64 value) {
    return (mask & ~(15ULL << (index << 2))) | (value << (index << 2));
}

int main() {
    uint64 mask = 0ULL;
    for(int i=0ULL; i<16; i++)
        mask = set(mask, i, i);
    for(int i=0ULL; i<16; i++)
        printf("%d\n", get(mask, i));
    return 0;
}
