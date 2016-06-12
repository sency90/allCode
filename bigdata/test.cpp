#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;
char s[100];
vector<pair<int, int> > v;
int main() {
    int source;
    freopen("input.txt", "r", stdin);
    while(scanf("%[^\n]\n", s)!=EOF) {
        int first = 0;
        for(char *p=strtok(s," "); p; p=strtok(0," ")) {
            if(!isdigit(*p)) continue;
            if(first==0) source = atoi(p);
            else v.push_back(make_pair(source, atoi(p)));
            first++;
        }
        if(first==1) v.push_back(make_pair(source, -1));
    }
    for(int i=0; i<v.size(); i++) {
        printf("(%d, %d)\n", v[i].first, v[i].second);
    }
    fclose(stdin);
    return 0;
}
