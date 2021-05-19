#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
string cmd, buf, line;
deque<int> dq;
stringstream ss;
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> cmd;
        int n; cin >> n;
        getline(cin, line, '[');
        getline(cin, line, ']');
        if(!line.empty()) {
            ss.clear(); ss.str(line.c_str());
            while(getline(ss, buf, ',')) {
                int x; sscanf(buf.c_str(), "%d", &x);
                dq.push_back(x);
            }
        }

        bool iserror = false;
        int isfront = 1;
        for(int i=0; i<cmd.size(); i++) {
            if(cmd[i]=='R') isfront ^= 1;
            else {
                if(isfront) {
                    if(dq.empty()) {
                        iserror = true;
                        break;
                    }
                    dq.pop_front();
                }
                else {
                    if(dq.empty()) {
                        iserror = true;
                        break;
                    }
                    dq.pop_back();
                }
            }
        }

        if(iserror) puts("error");
        else if(dq.empty()) puts("[]");
        else if(isfront) {
            for(int i=0; i<dq.size(); i++) printf("%c%d", (i==0)?'[':',',dq[i]);
            printf("]\n");
        }
        else {
            for(int i=dq.size()-1; i>=0; i--) printf("%c%d", (i==(int)dq.size()-1)?'[':',',dq[i]);
            printf("]\n");
        }
        dq.clear();
    }
    return 0;
}
