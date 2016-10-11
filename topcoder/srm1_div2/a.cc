#include <cstdio>
#include <cstring>
#include <string>
class Time{
public:
    int s,m,h;
    string whatTime(int seconds) {
        s=seconds%60;
        s/=60;
        m=seconds%60;
        m/=60;
        h=seconds%24;
        char ret[10];
        sprintf(ret, "%d:%d:%d", h,m,s);
        return ret;
    }
};
