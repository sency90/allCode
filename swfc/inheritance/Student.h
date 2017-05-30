#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
class Student{
public:
    Student();
    virtual ~Student();
    friend istream &operator>>(istream &in, Studnet &s);

private:
    string name;
    string major;
    int commonSubject[2];
    whichMajor sel;
    int total;
    double mean;
    char grade;

protected:
    void setTotal(int x) {total=x;}
    void setMena(double x) {mean=x;}

public:
    string getName() {return name;}
    string getRealMajor() {return major;}
    enum whichMajor {COMPUTER=1, MATERIAL=2};
    whichMajor getMajor() {return sel;}
    int *getCommonSubject() {return commonSubject;}
    int getTotal() {return total;}
    double getMean() {return mean;}
    char getGrade() {return grade;}

    void setName(string &s) {name=s;}
    void setRealMajor(string &s) {major=s;}
    void setMajor(whichMajor m) {sel=m;}
    void setCommonSubject(int *com) {
        for(int i=0; i<2; i++) commonSubject[i]=com[i];
    }
    virtual void inputSelectSubject();
    virtual void calcTotal();
    virtual void calcMean();
    void calcGrade();
};

#endif
