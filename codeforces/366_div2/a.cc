#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int n;
string str[2] = {"I hate", "I love"};
void f(int x, int s) {
    if(x==n) {
        cout << str[s] << " it";
        return;
    } else {
        cout << str[s] << " that ";
        f(x+1,s^1);
    }
}
int main() {
    scanf("%d", &n);
    f(1,0);
    return 0;
}
