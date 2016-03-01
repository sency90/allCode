#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
pair<int, char> chk[26];
bool cmp(const pair<int, int> a, const pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    } else return a.first > b.first;
}
int main() {
    char c;
    for(int i=0; i<26; i++) {
        chk[i].first = 0;
        chk[i].second = 'a'+i;
    }
    bool isIn = false;
    while(true) {
        while((c=getchar())!='\n' && c!=EOF && c!='\r') {
            if(c==' ') continue;
            chk[c-'a'].first++;
            isIn = true;
        } if(c==EOF) break;
    }
    stable_sort(chk, chk+26, cmp);
    if(isIn) printf("%c", chk[0].second);
    for(int i=1; i<26; i++) {
        if(chk[i].first == chk[i-1].first) printf("%c", chk[i].second);
        else break;
    }
    return 0;
}
