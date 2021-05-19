#include <stdio.h>
#include <set>
#include <cstring>
using namespace std;
set<int> s;
int main() {
    int t, num;
    char op[7];
    scanf("%d ", &t);
    while(t--) {
        scanf("%s", op);
        if(!strcmp(op, "all")) {
                for(int i=1; i<=20; i++) s.insert(i);
                continue;
        } else if(!strcmp(op, "empty")) {
            s.clear();
            continue;
        } else scanf("%d", &num);

        if(!strcmp(op, "add")) s.insert(num);
        else if(!strcmp(op, "check")) {
            auto x = s.find(num);
            if(x!=s.end()) puts("1");
            else puts("0");
        } else if(!strcmp(op, "remove")) {
            s.erase(num);
        } else if(!strcmp(op, "toggle")) {
            auto x = s.find(num);
            if(x!=s.end()) s.erase(num);
            else s.insert(num);
        }
    }
}
