#include <cstdio>
#include <cstring>
using namespace std;
char paper[65536];
char paper_bak[65536];
int seed = 3;

int pseudo_rand() {
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int main() {
    for(int i=0; i<1024; i++) {
        int len = pseudo_rand()%7;
        dic_len[i] = len;
        dic[i][]
    }
    return 0;
}
