#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
stack<pair<int, int> > s;
char h[1000001];
char n[37];
int main() {
    scanf("%s", h);
    scanf("%s", n);
    int hlen = strlen(h), nlen = strlen(n);
    pair<int, int> p;
    if(nlen == 1) {
        for(int i=0; i<hlen; i++) {
            if(h[i]==n[0]) {
                h[i]='#';
            }
        }
    } else {
        for(int i=0; i<hlen; i++) {
            if(h[i]==n[0]) {
                s.push(make_pair(i, 0));
            } else {
                if(s.empty()) continue;
                else {
                    p = s.top();
                    if(h[i]==n[p.second+1]) {
                        s.push(make_pair(i, p.second+1));
                        if(p.second+1==nlen-1) {
                            for(int j=0; j<nlen; j++) {
                                h[s.top().first]='#';
                                s.pop();
                            }
                        }
                    } else {
                        while(!s.empty()) s.pop();
                    }
                }
            }
        }
    }
    bool isIn = false;
    for(int i=0; i<hlen; i++) {
        if(h[i]=='#') continue;
        else {
            isIn = true;
            putchar(h[i]);
        }
    }
    if(!isIn) printf("FRULA");
    return 0;
}
