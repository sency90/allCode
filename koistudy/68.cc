#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    if(s == "A") puts("best!!!");
    else if(s == "B") puts("good!!");
    else if(s == "C") puts("run!");
    else if(s == "D") puts("slowly~");
    else puts("what?");
    return 0;
}
