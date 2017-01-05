#include <cstdio>
#include <vector>
using namespace std;
class InterestingDigits{
public:
    bool calc(int x, int b) {
        int sum=0;
        while(x!=0) {
            sum+=x%b;
            x/=b;
        }
        if(sum%b==0) return true;
        else return false;
    }
    vector<int> digits(int base) {
        vector<int> ans;
        for(int j=2; j<base; j++) {
            bool hasAns=true;
            for(int i=base+1; i<=base<<1; i++) {
                if(i%j==0) {
                    if(!calc(i,j)) {
                        hasAns=false;
                        break;
                    }
                }
            }
            if(hasAns) ans.push_back(j);
        }
        return ans;
    }
};
