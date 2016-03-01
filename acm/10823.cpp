#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main() {
    char str[10001];
    string s;
    int sum=0;
    while(scanf("%s", str)!=EOF) {
        s+=str;
    }
    istringstream iss(s);

    string number;
    while(getline(iss, number, ',')) {
        sum += stoi(number);
    }
    printf("%d", sum);
    return 0;
}
