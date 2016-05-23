//물에 관한 배열 wno를 만들어서 (i,j)에 언제 물이 차는지 기록
//이렇게 해서 풀면 쉽다.
//그런데 이게 ... 오래걸렸던 이유는
//q.size()를 반복문 돌릴때 int sz = q.size();로 해서 sz를 받은게 아니라
//직접 반복문의 limit부분에 q.size()를 사용해서 멍청이 같이 에러가 났었음.

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
char m[50][51];
bool chk[50][51], isBrk=false;
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int wno[50][51];
queue<pair<int,int> > w, q;
int main() {
    int r, c;
    pair<int,int> tmp, s;
    scanf("%d%d",&r,&c);
    memset(wno, 0x3f, sizeof(wno));
    for(int i=0; i<r; i++) {
        scanf("%s", m[i]);
        for(int j=0; j<c; j++) {
            if(m[i][j]=='S') {
                s = make_pair(i,j);
                q.push(s);
            } else if(m[i][j]=='*') {
                w.push(make_pair(i,j));
                wno[i][j]=1;
                chk[i][j] = true;
            }
        }
    }
    int nx, ny, inf=0x3f3f3f3f;
    while(!w.empty()) {
        tmp = w.front(); w.pop();
        for(int i=0; i<4; i++) {
            nx = tmp.first + dx[i];
            ny = tmp.second + dy[i];
            if(nx<0||ny<0||nx>=r||ny>=c) continue;
            if(chk[nx][ny]) continue;
            if(m[nx][ny]!='.'&&m[nx][ny]!='S') {
                wno[nx][ny]=inf;
                continue;
            }
            wno[nx][ny] = wno[tmp.first][tmp.second]+1;
            chk[nx][ny] = true;
            w.push(make_pair(nx, ny));
        }
    }
    memset(chk, false, sizeof(chk));
    chk[s.first][s.second] = true;
    int cnt=1, ans=0;
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            tmp = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                nx = tmp.first + dx[i];
                ny = tmp.second + dy[i];
                if(nx<0||ny<0||nx>=r||ny>=c) continue;
                if(chk[nx][ny]) continue;
                if(m[nx][ny]=='X') continue;
                if(cnt+1 < wno[nx][ny]) {
                    chk[nx][ny] = true;
                    if(m[nx][ny]=='D') {
                        ans=cnt;
                        break;
                    }
                    q.push(make_pair(nx, ny));
                }
            }
            if(ans>0) break;
        }
        if(ans>0) break;
        cnt++;
    }
    if(ans>0) printf("%d", ans);
    else puts("KAKTUS");
    return 0;
}
