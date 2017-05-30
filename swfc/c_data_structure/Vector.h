#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <stdio.h>
#include <stdlib.h>
typedef unsigned int ui;
template <class T>
class Vector{
private:
    unsigned int realsz,cursz;
    T *v;
    void inc(ui x) {
        T *tmp = (T*)calloc(x+1, sizeof(T));
        for(ui i=0; i<cursz; i++) {
            tmp[i] = v[i];
        }
        realsz=x;
        v=tmp;
    }
public:
    Vector():realsz(8),cursz(0){ v = (T*)calloc(9,sizeof(T)); }
    Vector(int n):cursz(0){
        if(n<=8) Vector();
        else {
            int i=0;
            for(; (1<<i)<n; i++);
            realsz=(1<<i);
            v = (T*)calloc(realsz,sizeof(T));
        }
    }
    Vector(int n, T data):cursz(0) {
        if(n<=8) {
            realsz=8;
            Vector();
            for(int i=0; i<n; i++) v->push_back(data);
        } else {
            Vector(n);
            for(int i=0; i<n; i++) v->push_back(data);
        }
    }

    bool empty() { return (cursz==0); }
    inline ui size() { return cursz; }
    void push_back(T x) {
        if(cursz == realsz) inc(realsz<<1);
        v[cursz++]=x;
    }
    T pop_back() { return v[cursz--]; }
    T operator[](int i) { return *(v+i); }
    inline ui realsize() {return realsz;}

    T* begin() { return &v[0]; }
    T* end() { return &v[cursz]; }
};
#endif
