#ifndef __STUDENT_COMPUTER_H__
#define __STUDENT_COMPUTER_H__
#include "Student.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
class StudentComputer: public Student {
public:
    StudentComputer();
    virtual ~StudentComputer();
    friend ostream &operator<<(ostream &out, StudentComputer &sc);

private:
    int selectSubject[3];

public:
    void inputSelectSubject();
    void calcTotal();
    void calcMean();
};
#endif
