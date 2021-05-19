#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string s;
vector<string> v;
int p[1<<9][1<<9][2];
void makeL(int & x, int & y, int &t) {
    int nx=x, ny=2*y;
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            p[i][j][t^1] = p[i][ny-j-1][t^1] = p[i][j][t];
        }
    }
    t^=1;
    y*=2;
}
void makeR(int & x, int & y, int & t) {
    int nx=x, ny=2*y;
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            p[i][y+j][t^1] = p[i][j][t];
        }
    }
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            p[i][j][t^1] = p[i][ny-j-1][t^1];
        }
    }
    t^=1;
    y*=2;
}

void makeU(int &x, int &y, int &t) {
    int nx=2*x, ny=y;
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            p[i][j][t^1] = p[nx-i-1][j][t^1] = p[i][j][t];
        }
    }
    t^=1;
    x*=2;
}
void makeD(int &x, int &y, int &t) {
    int nx=2*x, ny=y;
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            p[x+i][j][t^1] = p[i][j][t];
        }
    }
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            p[i][j][t^1] = p[nx-i-1][j][t^1];
        }
    }
    t^=1;
    x*=2;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tog = 0;

    p[0][0][tog] = 0;
    p[0][1][tog] = 1;
    p[1][0][tog] = 2;
    p[1][1][tog] = 3;

    int k; cin >> k;
    int lim = k*2;
    for(int i=0; i<lim; i++) {
        cin >> s;
        v.emplace_back(s);
    }
    int h; cin >> h;

    int x=2,y=2;
    for(int i=v.size()-1; i>=0; i--) {
        if(v[i] == "R") makeR(x,y,tog);
        else if(v[i] == "L") makeL(x,y,tog);
        else if(v[i] == "U") makeU(x,y,tog);
        else if(v[i] == "D") makeD(x,y,tog);
    }

    lim = 1<<k;
    /*
    puts("");
    for(int i=0; i<lim; i++) {
        for(int a=0; a<2; a++) {
            for(int j=0; j<lim; j++) {
                for(int b=0; b<2; b++) {
                    printf("%d ", p[i*2+a][j*2+b][tog]);
                }
            }
            puts("");
        }
    }
    puts("");
    */

    for(int i=0; i<lim; i++) {
        for(int j=0; j<lim; j++) {
            for(int a=0; a<2; a++) {
                for(int b=0; b<2; b++) {
                    if(p[i*2+a][j*2+b][tog] == h) {
                        printf("%d ", a*2+b);
                        goto BRK;
                    }
                }
            }
BRK:;
        }
        puts("");
    }
    return 0;
}
