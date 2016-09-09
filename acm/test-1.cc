#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n=10;

    vector<int> v;
    for(int i=0; i<n; i++) v.push_back((i*107-24+i*i-i*i*i+i*i*i*i)%53047);
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), 1000);
    printf("ANSWER: %d\n", *it);

    puts("");
    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++) {
        printf("VALUE: %d\n", *it);
    }

    puts("");
    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++) {
        printf("INDEX: %lu\n", it-v.begin());
    }


    map<int, int> d;
    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++) {
        d[it-v.begin()] = *it;
    }

    puts("");
    for(map<int, int>::iterator it = d.begin(); it!=d.end(); it++) {
        printf("해당 맵의 인덱스: %d\n", (*it).first);
        printf("해당 맵의 값: %d\n", it->second);
    }


    return 0;
}
