#include <iostream>
#include "Student.h"
#include "StudentComputer.h"
#include "StudentMaterial.h"
using namespace std;
class StudentHandler{
public:
    StudentHandler();
    virtual ~StudnetHandler();
    const int MAX_STUDENT=3;

private:
    Studnet **students;
    unsigned int sz;

public:
    void input();
    void print();
    inline unsigned int size() {return sz;}
};

