#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class BinaryCode{
public:
    int c(char x) { return x-'0'; }
    vector<string> decode(string msg) {
        vector<string> ret;
        for(int z=0; z<2; z++) {
            string s;
            int x = c(msg[0]);
            if(x==0) {
                if(z==0) s="00";
                else s="NONE ";
            } else if(x==1) {
                if(z==0) s="01";
                else s="10";
            } else if(x==2) {
                if(z==0) s="NONE ";
                else s="11";
            }

            for(int i=1; i<msg.size(); i++) {
                x=c(msg[i]);
                int dif = x-c(s[i])-c(s[i-1]);
                if(dif<0||dif>1) {
                    s="NONE ";
                    break;
                }
                s+=('0'+dif);
            }
            ret.push_back(s.substr(0,s.size()-1));
        }
        return ret;
    }
};
int main() {
    string s;
    cin >> s;
    BinaryCode bc;
    auto ans = bc.decode(s);
    cout << ans[0] << " " << ans[1];
    return 0;
}
