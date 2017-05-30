#ifndef __STUDENT_MATERIAL_H__
#define __STUDENT_MATERIAL_H__
#include "Student.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
class StudentMaterial: public Student {
public:
    StudentMaterial();
    virtual ~StudentMaterial();

private:
    int selectSubject[2];

public:
    void inputSelectSubject();
    void calcTotal();
    void calcMean();
};
#endif
