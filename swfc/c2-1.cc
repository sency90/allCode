#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
vector<int> o[6];
char s[5][10];
int num[13];
bool chk[13];
int main() {
    //freopen("input.txt", "r", stdin);
    for(int i=0; i<5; i++) scanf("%s", s[i]);
    v.push_back(make_pair(0,4)); //0
    v.push_back(make_pair(1,1)); //1
    v.push_back(make_pair(1,3)); //2
    v.push_back(make_pair(1,5)); //3
    v.push_back(make_pair(1,7)); //4
    v.push_back(make_pair(2,2)); //5
    v.push_back(make_pair(2,6)); //6
    v.push_back(make_pair(3,1)); //7
    v.push_back(make_pair(3,3)); //8
    v.push_back(make_pair(3,5)); //9
    v.push_back(make_pair(3,7)); //10
    v.push_back(make_pair(4,4)); //11

    o[0].push_back(1); o[0].push_back(2); o[0].push_back(3); o[0].push_back(4);
    o[1].push_back(0); o[1].push_back(3); o[1].push_back(6); o[1].push_back(10);
    o[2].push_back(4); o[2].push_back(6); o[2].push_back(9); o[2].push_back(11);
    o[3].push_back(10); o[3].push_back(9); o[3].push_back(8); o[3].push_back(7);
    o[4].push_back(11); o[4].push_back(8); o[4].push_back(5); o[4].push_back(1);
    o[5].push_back(7); o[5].push_back(5); o[5].push_back(2); o[5].push_back(0);

    vector<int> idx;
    for(int i=0; i<int(v.size()); i++) {
        int x=v[i].first, y=v[i].second;
        if(s[x][y]=='x') {
            num[i]=0;
            idx.push_back(i);
        } else if(s[x][y]!='.') {
            int tmp = s[x][y]-'A'+1;
            chk[tmp]=true;
            num[i]=tmp;
        }
    }

    vector<int> w;
    for(int i=1; i<=12; i++) {
        if(!chk[i]) w.push_back(i);
    }

    do{
        for(int i=0; i<w.size(); i++) {
            num[idx[i]] = w[i];
        }
        bool hasAns=true;
        for(int i=0; i<6; i++) {
            int sum=0;
            for(int j=0; j<4; j++) {
                sum+=num[o[i][j]];
            }
            if(sum!=26) {
                hasAns = false;
                break;
            }
        }
        if(hasAns) break;
    }while(next_permutation(w.begin(), w.end()));

    s[0][4]=num[0]-1+'A';
    s[1][1]=num[1]-1+'A';
    s[1][3]=num[2]-1+'A';
    s[1][5]=num[3]-1+'A';
    s[1][7]=num[4]-1+'A';
    s[2][2]=num[5]-1+'A';
    s[2][6]=num[6]-1+'A';
    s[3][1]=num[7]-1+'A';
    s[3][3]=num[8]-1+'A';
    s[3][5]=num[9]-1+'A';
    s[3][7]=num[10]-1+'A';
    s[4][4]=num[11]-1+'A';

    for(int i=0; i<5; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}
