#include <cstdio>
#include <vector>
using namespace std;
class WidgetRepairs{
public:
    int days(vector<int> arr, int lim) {
        int cnt=0, sum=0;
        for(auto &p : arr) {
            sum+=p;
            if(sum>=lim) sum-=lim;
            else sum=0;
            cnt++;
        }
        cnt+=sum/lim;
        if(sum%lim) cnt++;
        return cnt;
    }
};
