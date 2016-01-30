#include <stdio.h>
#include <iostream>
using namespace std;

#define NEWINT(x) int x; scanf("%d", &x)
#define PRINT(x) cout << x << endl

int calNumOfDay(int month, int date) {
    switch(month){
        case 1:
            return date;
        case 3:
            return calNumOfDay(--month, date+28);
        case 5:
        case 7:
        case 10:
        case 12:
            return calNumOfDay(--month, date+30);
        case 2:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
            return calNumOfDay(--month, date+31);
        default:
            return date;
    }
}

int main() {

    enum Day {SUN, MON, TUE, WED, THR, FRI, SAT};

    NEWINT(month);
    NEWINT(date);

    int totalDay = calNumOfDay(month, date);

    switch(totalDay%7) {
        case 0: PRINT("SUN"); break;
        case 1: PRINT("MON"); break;
        case 2: PRINT("TUE"); break;
        case 3: PRINT("WED"); break;
        case 4: PRINT("THU"); break;
        case 5: PRINT("FRI"); break;
        case 6: PRINT("SAT"); break;
    }

    return 0;
}
