#include "StudentMaterial.h"
StudentMaterial::StudentMaterial(){}
void StudentMaterial::inputSelectSubject():Student() {
    for(int i=0; i<2; i++) cin >> selectSubject[i];
}
void StudentMaterial::calcTotal() {
    int *p = getCommonSubject();
    int res=0;
    for(int i=0; i<2; i++) {
        res += p[i]+selectSubject[i];
    }
    setTotal(res);
}
void StudentMaterial::calcMean() {
    calcTotal();
    setMean((double)getTotal()/4.0);
}

