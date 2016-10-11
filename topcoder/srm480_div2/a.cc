#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Cryptography{
public:
    long long f(int x, vector<int> &num) {
        num[x]++;
        long long ret=1LL;
        for(int i=0; i<num.size(); i++) {
            ret*=num[i];
        }
        num[x]--;
        return ret;
    }
    long long encrypt(vector<int> numbers) {
        long long mx=0LL;
        for(int i=0; i<numbers.size(); i++) {
            mx = max(mx,f(i, numbers));
        }
        return mx;
    }
};
