#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> A;
int main() {
    A.resize(5, vector<int>(10));
    printf("%lu, %lu", A.size(), A[0].size());
    for(int i=0; i<5; i++) {
        for(int j=0; j<10; j++) {
            printf("%d", A[i][j]);
        }
        puts("");
    }
}
