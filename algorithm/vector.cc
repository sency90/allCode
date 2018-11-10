#include "Vector.h"
using namespace std;

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
	idx++;
	if(idx>=sz) {
		sz<<=1;
		expand(sz);
	}
	arr[idx] = x;
}

template <class T>
void Vector<T>::resize(int size) {
	if(size<=0) clear();
	else idx = size-1;
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
