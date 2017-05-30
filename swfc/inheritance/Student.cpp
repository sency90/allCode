#include "Student.h"
Student::Student():total(0),mean(0.0),grade('F'){}

istream &operator>>(istream &in, Student &s) {
    in >> s.name >> s.major >> s.commonSubject[0] >> s.commonSubject[1];
    return in;
}

void Student::calcGrade() {
    if(mean>=90.0) grade='A';
    else if(mean>=80.0) grade='B';
    else if(mean>=70.0) grade='C';
    else if(mean>=60.0) grade='D';
    else grade='F';
}
