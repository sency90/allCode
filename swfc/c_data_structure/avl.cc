#ifndef __AVL_H__
#define __AVL_H__
#include <stdio.h>
#include <stdlib.h>
typedef unsigned int ui;
template <class T>
class Vector{
private:
    unsigned int sz,idx;
    T *v;
    void inc(ui x) {
        T *tmp = calloc(x, sizeof(T));
        for(ui i=0; i<sz; i++) {
            tmp->push_back(v[i]);
        }
        sz=x;
        v=tmp;
    }
public:
    Vector():sz(8),idx(0){ v = calloc(8,sizeof(T)); }
    Vector(int n){
        if(n<=8) Vector();
        else {
            int i=0;
            for(; (1<<i)<n; i++);
            v = calloc((1<<i),sizeof(T));
        }
    }
    Vector(int n, T data) {
        if(n<=8) {
            Vector();
            for(int i=0; i<n; i++) v->push_back(data);
        } else {
            Vector(n);
            for(int i=0; i<n; i++) v->push_back(data);
        }
    }

    bool empty() { return (idx==0); }
    inline ui size() { return sz; }
    void push_back(T x) {
        if(idx+1 == sz) inc(sz<<1);
        v[idx++]=x;
    }
};
#endif
