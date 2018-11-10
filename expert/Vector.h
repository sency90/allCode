#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <cstdio>
#include <cstdlib>
using namespace std;
template <class T>
class Vector{
private:
    int sz,idx;
    T *arr;

private:
    void expand(int size);

public:
    Vector();
    virtual ~Vector();
    void clear();
    void push_back(T x);
    void pop_back() { idx--; }
    void resize(int size);
    int size() const;
    T& operator[](int at) const;
};

//public functions
template <class T>
Vector<T>::Vector():sz(1),idx(0) {
	arr = (T*)malloc(sizeof(T));
}

template <class T>
Vector<T>::~Vector() {
	if(arr) free(arr);
}

template <class T>
void Vector<T>::clear() {
	idx=0;
}

template <class T>
void Vector<T>::push_back(T x) {
	if(idx>=sz) {
		sz<<=1;
		expand(sz);
	}
	arr[idx++] = x;
}

template <class T>
void Vector<T>::resize(int size) {
	if(size<=0) clear();
	else idx = size;
	//if(idx >= (1<<30)) exit(1); //error
	if(idx >= sz) {
		while(idx>=sz) sz<<=1;
		do {
			arr = (T*)realloc(arr, (sz)*sizeof(T));
		} while(!arr);
	}
}

template <class T>
int Vector<T>::size() const { return idx; }

template <class T>
T& Vector<T>::operator[](int at) const {
	return arr[at];
}

//private functions
template <class T>
void Vector<T>::expand(int size) {
	do {
		arr = (T*)realloc(arr, (size)*sizeof(T));
	} while(!arr);
}

#endif
