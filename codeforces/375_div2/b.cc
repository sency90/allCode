#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    bool in=false;
    int cnt=0, pcnt=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='(') {
            pcnt=0;
            in=true;
            continue;
        } else if(s[i]==')') {
            if(pcnt) cnt++;
            in=false;
            continue;
        }
        if(in) {
            if(s[i]=='_') {
                if(pcnt) cnt++;
                pcnt=0;
                if(s[i+1]=='_') i++;
                continue;
            } else {
                pcnt++;
            }
        }
    }

    int cnt2=0, pans=0;
    bool out=true;
    for(int i=0; i<n; i++) {
        if(s[i]=='(') {
            pans=0;
            out=false;
            continue;
        } else if(s[i]==')') {
            pans=0;
            out=true;
            continue;
        }
        if(out) {
            if(s[i]=='_') {
                pans=0;
                if(s[i+1]=='_') i++;
                continue;
            } else {
                pans++;
            }
        }
        cnt2=max(cnt2,pans);
    }
    printf("%d %d\n",cnt2, cnt);
    return 0;
}
