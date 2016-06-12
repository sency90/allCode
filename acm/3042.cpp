//hesse의 공식을 써서 풀었다.
//세점이 한 직선위에 있으려면, 세점을 이루는 삼각형의 넓이가 0이되는 경우이다.
#include <stdio.h>
#include <vector>
using namespace std;
typedef pair<int,int> pi;
vector<pi> v;
char tmp[101];
bool f(pi& a, pi& b, pi& c) {
    if(a.first*b.second + b.first*c.second + c.first*a.second == b.first*a.second + c.first*b.second + a.first*c.second) return true;
    else return false;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", tmp);
        for(int j=0; j<n; j++) {
            if(tmp[j]!='.') v.push_back(make_pair(i,j));
        }
    }
    long long cnt = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            for(int k=j+1; k<v.size(); k++) {
                if(f(v[i],v[j],v[k])) cnt++;
            }
        }
    }
    printf("%lld", cnt);
    return 0;
}
