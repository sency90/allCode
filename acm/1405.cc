#include<cstdio>
int N;
bool visit[31][31];
int px[4] = { 1, -1, 0, 0 };
int py[4] = { 0, 0, -1, 1 };
double ans;
double temp[4];
void start(int a, int b, double cnt){
    visit[a][b] = true;
    if (N == 0){
        visit[a][b] = false;
        ans += cnt;
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!visit[a + py[i]][b + px[i]]){
            N--;
            start(a + py[i], b + px[i], cnt*temp[i]);
            N++;
            visit[a + py[i]][b + px[i]] = false;
        }
    }

}
int main(){
    scanf("%d %lf %lf %lf %lf", &N, &temp[0], &temp[1], &temp[2], &temp[3]);
    for (int i = 0; i < 4; i++){
        temp[i] *= 0.01;
    }
    start(15, 15, 1.0);
    printf("%.9lf\n", ans);
}
