#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;

#if 1 //strLen
size_t strLen(const char *s) {
    return strlen(s);
}
size_t strLen(const string & s) {
    return s.size();
}
template <typename String, typename... Strings>
size_t strLen(const String & s, Strings... ss) {
    return s.size() + strLen(ss...);
}
#endif


#if 1 //strAppend
template <typename String>
string strAppend(string & ret, const String & s) {
    if(ret.capacity() < s.size()) ret.reserve(s.size());
    ret.append(s);
    return ret;
}
template <typename String, typename... Strings>
string strAppend(string & ret, const String & s, Strings... ss) {
    ret.append(s);
    strAppend(ret,ss...);
    return ret;
}
#endif

#if 1 //strcat
template <typename String>
string strcat(const String & s) {
    return string(s);
}
template <typename String, typename... Strings>
string strcat(const String & s, Strings... ss) {
    string ret;
    int len = strLen(s, ss...);
    printf("len:%d\n", len);
    ret.reserve(len);
    printf("ret's capacity:%lu\n", ret.capacity());

    strAppend(ret, s, ss...);
    return ret;
}
#endif

int main() {
    string a = "hi ";
    string b = "he ";
    string c = "plzrun";
    string ret = strcat(a,b,c);
    printf("ret:%s, ret.capacity():%lu, ret.size():%lu\n", ret.c_str(), ret.capacity(), ret.size());
    return 0;
}