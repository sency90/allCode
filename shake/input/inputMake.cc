#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;
string pre = "input_", sfx=".txt", fname, s;
ofstream out;
int main() {
    ios::sync_with_stdio(false);
    srand(time(0));
    for(int i=10; i<=100; i++) {
        fname=pre+to_string(i)+sfx;
        out=ofstream(fname);
        out.tie(0);
        s.clear();

        int strlen=0, k=0;
        if(i>=90) strlen=100000;
        else strlen = 10000+rand()%90001;

        if(i<=20) k=20%i;
        else if(i<=40) k=strlen/100;
        else if(i<=60) k=strlen/10;
        else if(i<=80) k=strlen;
        else if(i<=90) k=strlen*10;
        else if(i<=98) k=rand()%1000001;
        else k=1000000;
        assert(strlen>=1); assert(strlen<=100000);
        assert(k>=0); assert(k<=1000000);

        out << strlen << " " << k << "\n";

        for(int i=0; i<strlen; i++) {
            char c='a'+rand()%26;
            s+=c;
        }
        out << s;
    }
}
