#include <iostream>
using namespace std;
char a[1001];
int res;
int func(int num){
    long long result=0;
    while(num>=10){
        result += num % 10;
        num /= 10;
    }
    result += num;
    if(result >= 10) return func(result);
    else return result;
}
int main() {
    while(1){
        cin >> a;
        if(a[0] == '0') break;
        for(int i=0;a[i]!='\0';i++)
            res += a[i] -'0';
        res = func(res);
        cout << res << '\n';
    }
    return 0;
}
