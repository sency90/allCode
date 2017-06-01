#include <iostream>
using namespace std;
typedef pair<int,int> pii;
pii co[6][4];
char s[6][11];
int star[6][4];
int main() {
    int test=0;
    freopen("input.txt", "r", stdin);
    for(int i=0; i<5; i++) scanf("%s", s[i]);
    printf("test: %d\n", test++);
    int idx=0;
    for(int j=0; s[1][j]; j++) {
        if(s[1][j]=='x') star[0][idx++] = 0;
        else if(s[1][j]!='.') star[0][idx++] = s[1][j]-'A'+1;
    }
    printf("test: %d\n", test++);

    idx=0;
    for(int i=0,j=4; s[i][j]; i++,j++) {
        if(s[i][j]=='x') star[1][idx++] = 0;
        else if(s[i][j]!='.') star[1][idx++] = s[i][j]-'A'+1;
    }

    printf("test: %d\n", test++);
    idx=0;
    for(int i=1,j=7; s[i][j]; i++,j--) {
        if(s[i][j]=='x') star[2][idx++] = 0;
        else if(s[i][j]!='.') star[2][idx++] = s[i][j]-'A'+1;
    }

    printf("test: %d\n", test++);
    idx=0;
    for(int j=7; s[3][j]; j--) {
        if(s[3][j]=='x') star[3][idx++] = 0;
        else if(s[3][j]!='.') star[3][idx++] = s[3][j]-'A'+1;
    }

    printf("test: %d\n", test++);
    idx=0;
    for(int i=4,j=4; i!=0; i--,j--) {
        if(s[i][j]=='x') star[4][idx++] = 0;
        else if(s[i][j]!='.') star[4][idx++] = s[i][j]-'A'+1;
    }

    printf("test: %d\n", test++);
    idx=0;
    for(int i=3,j=1; i>=0; i--,j++) {
        if(s[i][j]=='x') star[5][idx++] = 0;
        else if(s[i][j]!='.') star[5][idx++]=s[i][j]-'A'+1;
    }

    printf("test: %d\n", test++);
    idx=0;
    for(int i=0; i<6; i++) {
        for(int j=0; j<4; j++) {
            printf("%d ", star[i][j]);
        } puts("");
    }

    co[0][0] = make_pair(4,3);
    co[0][1] = make_pair(5,2);
    co[0][2] = make_pair(1,1);
    co[0][3] = make_pair(2,0);
    co[1][0] = make_pair(5,3);
    co[1][1] = make_pair(0,2);
    co[1][2] = make_pair(2,1);
    co[1][3] = make_pair(3,0);
    co[2][0] = make_pair(0,3);
    co[2][1] = make_pair(1,2);
    co[2][2] = make_pair(3,1);
    co[2][3] = make_pair(4,0);
    co[3][0] = make_pair(1,3);
    co[3][1] = make_pair(2,2);
    co[3][2] = make_pair(4,1);
    co[3][3] = make_pair(5,0);
    co[4][0] = make_pair(2,3);
    co[4][1] = make_pair(3,2);
    co[4][2] = make_pair(5,1);
    co[4][3] = make_pair(0,0);
    co[5][0] = make_pair(3,3);
    co[5][1] = make_pair(4,2);
    co[5][2] = make_pair(0,1);
    co[5][3] = make_pair(1,0);

    for()

    return 0;
}
