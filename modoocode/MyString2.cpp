#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
using namespace std;

class MyString{
    char *string_content;
    int string_length;

    int memory_capacity;

    public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &str);
	MyString(MyString &&str) noexcept;

    void reserve(int size);
    MyString operator+(const MyString &s);
	MyString& operator=(const MyString &s);
	MyString& operator=(MyString &&s);
    virtual ~MyString();

    int length() const;

    void print();
    void println();

};

//General Constructor
MyString::MyString() {
    cout << "[Call General Constructor - T()]\n";
    string_length = 0;
    memory_capacity = 0;
    string_content = nullptr;
}

//Copy Constructor
MyString::MyString(const char *str) {
    cout << "[Call Copy Constructor - T(const char *)]\n";
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

	for(int i=0; i<string_length; i++) {
		string_content[i] = str[i];
	}
}

//Move Constructor
MyString::MyString(MyString && str) noexcept {
	cout << "[Call Move Constructor - T(T&&)]\n";
	string_length = str.string_length;
	string_content = str.string_content;
	memory_capacity = str.memory_capacity;

	//!!!!!!!!!!!!!!!!CAUTION!!!!!!!!!!!!!!!!!!!!!!!!!
	//Prevents memory deallocation upon temporary object destruction
	str.string_content = nullptr;
	str.string_length = str.memory_capacity = 0;
}

MyString::~MyString() {
	if(string_content != nullptr) {
		delete[] string_content;
		string_content = nullptr;
	}
}

void MyString::reserve(int size) {
    if(size > memory_capacity) {
        char *prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for(int i=0; i<string_length; i++) {
            string_content[i] = prev_string_content[i];
        }

        if(prev_string_content != nullptr) {
			delete[] prev_string_content;
			prev_string_content = nullptr;
		}
    }
}

MyString MyString::operator+(const MyString &rhs) {
	MyString str;
	const MyString &lhs = *this;
	str.reserve(lhs.string_length + rhs.string_length);
	for(int i=0; i<lhs.string_length; i++) {
		str.string_content[i] = lhs.string_content[i];
	}
	for(int i=0; i<rhs.string_length; i++) {
		str.string_content[lhs.string_length + i] = rhs.string_content[i];
	}
	str.string_length = lhs.string_length + rhs.string_length;
	return str;
}

MyString& MyString::operator=(const MyString &rhs) {
	cout << "[Call 'T& operator=(const T&)]'\n";
	MyString &lhs = *this;
	if(lhs.memory_capacity < rhs.string_length) {
		if(lhs.string_content != nullptr) {
			delete[] lhs.string_content;
			lhs.string_content = nullptr;
		}
		lhs.string_content = new char[rhs.string_length];
		lhs.memory_capacity = rhs.string_length;
	}
	for(int i=0; i<rhs.string_length; i++) {
		lhs.string_content[i] = rhs.string_content[i];
	}
	lhs.string_length = rhs.string_length;
	return lhs;
}

MyString& MyString::operator=(MyString &&rhs) {
	cout << "[Call 'T& operator=(T &&)]'\n";
	MyString &lhs = *this;
	if(lhs.string_content != nullptr) {
		delete[] lhs.string_content;
		lhs.string_content = nullptr;
	}

	lhs.memory_capacity = rhs.memory_capacity;
	lhs.string_length = rhs.string_length;
	lhs.string_content = rhs.string_content;

	rhs.memory_capacity = rhs.string_length = 0;
	rhs.string_content = nullptr;
	return lhs;
}


int MyString::length() const { return string_length; }
void MyString::print() {
	for(int i=0; i<string_length; i++) cout << string_content[i];
}

void MyString::println() {
	for(int i=0; i<string_length; i++) cout << string_content[i];
	cout << "\n";
}

void mySwap(MyString &lhs, MyString &rhs) {
	MyString tmp = std::move(lhs);
	lhs = move(rhs);
	rhs = move(tmp);
}

//template<typename T, typename... Args>
//std::unique_ptr<T> mk_unique(Args&&... args) {
//    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
//}
template<typename T, typename... Args>
unique_ptr<T> mk_unique(Args... args) {
	unique_ptr<T> ret(new T(forward<Args>(args)...));
	return ret;
}

int main() {
	MyString str1("abc");
	MyString str2("def");
	cout << "========================================\n";
	cout << "mySwap(str1, str2)\n";
	mySwap(str1, str2);
	cout << "=> ";
	cout << "str1: "; str1.print(); cout << ", str2: "; str2.print(); cout << "\n";
	cout << "========================================\n";
	str1.print(); cout << " + "; str2.println();
	MyString str3 = str1 + str2;
	cout << "=> "; str3.println();

	unique_ptr<MyString> p = mk_unique<MyString>("ghi");

	return 0;
}
