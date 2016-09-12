#include <cstdio>
#include <bitset>
using namespace std;
int main() {
    bitset<64> mask;
    printf("%llu", mask.set(2).to_ullong());
    return 0;
}
