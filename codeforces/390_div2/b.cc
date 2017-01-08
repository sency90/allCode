#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string b[4];
bool hchk(int r, int c) {
    if(b[r][c]=='o') return false;
    else if(b[r][c]=='x') {
        if(b[r][c+1]=='.'&&b[r][c+2]=='x') return true;
        if(b[r][c+1]=='x'&&b[r][c+2]=='.') return true;
    } else {
        if(b[r][c+1]=='x'&&b[r][c+2]=='x') return true;
    }
    return false;
}
bool vchk(int r, int c) {
    if(b[r][c]=='o') return false;
    else if(b[r][c]=='x') {
        if(b[r+1][c]=='.'&&b[r+2][c]=='x') return true;
        if(b[r+1][c]=='x'&&b[r+2][c]=='.') return true;
    } else {
        if(b[r+1][c]=='x'&&b[r+2][c]=='x') return true;
    }
    return false;
}
bool rdiachk(int r, int c) {
    if(b[r][c]=='o') return false;
    else if(b[r][c]=='x') {
        if(b[r+1][c+1]=='.'&&b[r+2][c+2]=='x') return true;
        if(b[r+1][c+1]=='x'&&b[r+2][c+2]=='.') return true;
    } else {
        if(b[r+1][c+1]=='x'&&b[r+2][c+2]=='x') return true;
    }
    return false;
}
bool ldiachk(int r, int c) {
    if(b[r][c]=='o') return false;
    else if(b[r][c]=='x') {
        if(b[r+1][c-1]=='.'&&b[r+2][c-2]=='x') return true;
        if(b[r+1][c-1]=='x'&&b[r+2][c-2]=='.') return true;
    } else {
        if(b[r+1][c-1]=='x'&&b[r+2][c-2]=='x') return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i=0; i<4; i++) cin >> b[i];

    for(int r=0; r<4; r++) {
        for(int c=0; c<2; c++) {
            if(hchk(r,c)) return 0&puts("YES");
        }
    }
    for(int r=0; r<2; r++) {
        for(int c=0; c<4; c++) {
            if(vchk(r,c)) return 0&puts("YES");
        }
    }
    for(int r=0; r<2; r++) {
        for(int c=0; c<2; c++) {
            if(rdiachk(r,c)) return 0&puts("YES");
        }
        for(int c=2; c<4; c++) {
            if(ldiachk(r,c)) return 0&puts("YES");
        }
    }
    puts("NO");
    return 0;
}
