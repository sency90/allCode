#include "StudentHandler.h"
using namespace std;
StudentHandler::StudentHandler():sz(0U) {
    students = new Student*[MAX_STUDENT];
}

void StudentHandler::input() {
    while(cin >> students[i]) {
        if(students[i]->getMajor() == Student::COMPUTER) {
            StudentComputer *p = (StudentComputer*)students[i];
            p->inputSelectSubject();
            p->calcTotal();
            p->caclMean();
        } else {
            StudentMaterial *p = (StudentMaterial*)students[i];
            p->inputSelectSubject();
            p->calcTotal();
            p->caclMean();
        }
    }
}

void StudentHandler::print() {
    for(int i=0; i<size(); i++) {
        if(students[i]->getMajor == Student::COMPUTER) {
            StudentComputer *p = (StudentComputer*)students[i];
            cout << *p;
        } else {
            StudentMaterial *p = (StudentMaterial*)students[i];
            cout << *p;
        }
    }
}
