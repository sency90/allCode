#include <string>
#include <iostream>
#include <cstring>
using namespace std;
string DAY[]={"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
using namespace std;
int getDay(int y, int m, int d) {
    int j=y/100, k=y%100;
    return (d + (int)(((m+1)*26)/10) -2*j+k + (int)(j/4)+(int)(k/4) + 7000000) % 7;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int year, month, day;
    cin >> year >> month >> day;
    int idx = getDay(year,month,day);
    cout << "idx: "<< idx << "\n";
    cout << DAY[idx] << "\n";
    return 0;
}
