#ifndef __COMMON_FUNCTIONS_H__
#define __COMMON_FUNCTIONS_H__
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdarg>
#include <unistd.h>
#include <vector>
#include <map>
#define __DEBUG__
using namespace std;
class CommonFunctions{
    public:
        static void trimLeftTrailingSpaces(string &line) {
            if(line.size()==0U) return;
            int idx=0;

            for(int i=0; i<line.size(); i++) {
                if(!isspace(line[i])) {
                    idx = i;
                    break;
                }
            }

            line.erase(line.begin(), line.begin()+idx);
        }
        static void trimRightTrailingSpaces(string &line) {
            if(line.size()==0U) return;
            int idx=0;

            for(int i=line.size()-1; i>=0; i--) {
                if(!isspace(line[i])) {
                    idx = i+1;
                    break;
                }
            }

            line.erase(line.begin()+idx, line.end());
        }
        static void trimBothTrailingSpaces(string &line) {
            trimLeftTrailingSpaces(line);
            trimRightTrailingSpaces(line);
        }
        static bool putTrailingSlash(string &line) {
            bool ret = false;
            if(line.size()==0) ret = false;
            else if(line.back()=='/') ret = false;
            else ret = true;
            line += "/";
            return ret;
        }
        static void err(const char *fmt, ...) {
            va_list args;
            va_start(args, fmt); vprintf(fmt, args); va_end(args);
        }
        static void debug(const char *fmt, ...) {
#ifdef __DEBUG__
            va_list args;
            va_start(args, fmt), vprintf(fmt, args); va_end(args);
#endif
        }
};
#endif
