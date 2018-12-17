#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
using pii = pair<int,int>;
int seed = 3;
int pseudo_rand() {
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7fff;
}
char subs[256];
vector<pii> v;
int main() {
    int tc=100; printf("%d\n", tc);
    puts("");

    while(tc--) {
        //printf("[%d]\n", 15-tc);
        v.clear();
        for(int i=0; i<26; i++) {
            v.emplace_back(pseudo_rand(), i);
        }

        sort(v.begin(), v.end());
        subs[' '] = ' ';
        for(int i=0; i<v.size(); i++) {
            subs[i+'a'] = v[i].second + 'a';
        }

        string known = "the quick brown fox jumps over the lazy dog";
        int n = pseudo_rand() % 100 + 1;
        int th;
        if((tc & 1) == 0) th = pseudo_rand() % n;
        else th = pseudo_rand() % 100;

        //fprintf(stderr, "%d, %d\n", n, th);
        for(int i=0; i<n; i++) {
            if(i==th) {
                for(char c: known) putchar(subs[c]);
                puts("");
            } else {
                int len = pseudo_rand() % 90 + 11;
                for(int j=0; j<len; j++) {
                    int c = pseudo_rand()%40;
                    if(c>=26) putchar(' ');
                    else putchar(subs[c+'a']);
                }
                puts("");
            }
        }
        if(tc>0) puts("");
    }
    return 0;
}
