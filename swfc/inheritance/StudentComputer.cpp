#include "StudentComputer.h"
StudentComputer::StudentComputer(){}

void StudentComputer::inputSelectSubject() {
    for(int i=0; i<3; i++) cin >> selectSubject[i];
}
void StudentComputer::calcTotal() {
    int *p = getCommonSubject();
    int res=0;
    for(int i=0; i<2; i++) res += p[i];
    for(int i=0; i<3; i++) res += selectSubject[i];
    setTotal(res);
}
void StudentComputer::calcMean() {
    calcTotal();
    setMean((double)getTotal()/5.0);
}
