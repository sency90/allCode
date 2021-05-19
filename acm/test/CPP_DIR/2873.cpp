#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#define BIG 2000
using namespace std;
int r, c, mnr=0, mnc=0;
int uplim, lowlim;
string str, rStr;
int fdr[4] = {1, 0, -1, 0};
int fdc[4] = {0, 1, 0, 1};
int bdr[4] = {-1, 0, 1, 0};
int bdc[4] = {0, -1, 0, -1};
bool tar = false;
void search(int rs, bool isF) {
    if(isF) {
        if(rs+2<=mnr) {
            for(int i=0; i<c-1; i++) str += "R";
            str += "D";
            for(int i=0; i<c-1; i++) str += "L";
            str += "D";
            uplim += 2;
            if(!tar) {
                search(r-rs-1, false);
            } else {
                search(rs+2, true);
            }
        } else {
            int nr = rs, nc = 0;
            int len = 2*mnc+1;
            for(int i=0; i<len; i++) {
                if(nr+fdr[i%4]==mnr && nc+fdc[i%4]==mnc) {
                    if(!tar) {
                        //find out the min black tile
                        tar = true;
                        search(r-rs-1, false);
                    }
                    return;
                } else {
                    nr+=fdr[i%4];
                    nc+=fdc[i%4];
                    if(fdr[i%4]>0) str+="D";
                    else if(fdr[i%4]<0) str+="U";
                    else str+="R";
                }
            }
        }
    } else {
        if(rs-2>=mnr) {
            //search backward 2 rows.
            for(int i=0; i<c-1; i++) rStr += "R";
            rStr += "D";
            for(int i=0; i<c-1; i++) rStr += "L";
            rStr += "D";

            lowlim -= 2;
            if(!tar) {
                search(r-rs+1, true);
            } else {
                search(rs-2,false);
            }
        } else {
            int nr = rs, nc = c-1;
            int len = 2*(c-mnc)+1;
            for(int i=0; i<len; i++) {
                if(nr+bdr[i%4]==mnr && nc+bdc[i%4]==mnc) {
                    //find out the min black tile
                    if(!tar) {
                        tar = true;
                        search(r-rs+1, true);
                    }
                    return;
                } else {
                    nr+=bdr[i%4];
                    nc+=bdc[i%4];
                    if(bdr[i%4]>0) rStr+="U";
                    else if(bdr[i%4]<0) rStr+="D";
                    else rStr+="R";
                }
            }
        }
    }
}
int main() {
    scanf("%d %d", &r, &c);
    uplim = 0;
    lowlim = r-1;
    if(r%2==1) {
        c--;
        for(int i=0; i<r;) {
            for(int j=0; j<c; j++) str += "R";
            if(++i>=r) break;
            str +="D";
            for(int j=0; j<c; j++) str += "L";
            ++i;
            str+="D";
        }
        while(getchar()!=EOF);
    } else if(c%2==1) {
        r--;
        for(int i=0; i<c;) {
            for(int j=0; j<r; j++) str += "D";
            if(++i>=c) break;
            str+="R";
            for(int j=0; j<r; j++) str += "U";
            ++i;
            str+="R";
        }
        while(getchar()!=EOF);
    } else {
        int min = BIG, d;
        //for black tiles
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                scanf("%d", &d);
                if((i+j)%2==1) {
                    if(min > d) {
                        min = d;
                        mnr = i;
                        mnc = j;
                    }
                }
            }
        }
        search(0, true);
        if(!rStr.empty()) {
            reverse(rStr.begin(), rStr.end());
            str+=rStr;
        }
    }
    cout << str;
    return 0;
}
