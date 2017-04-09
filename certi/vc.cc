#include <iostream>
using namespace std;
template <typename T> class _vector{
    public:
    int sz, capa;
    T *arr;
    _vector() {
        sz=0;
        capa=32;
        arr = new T[capa];
    }
    _vector(int k) {
        sz=capa=k;
        arr = new T[k];
    }
    _vector(int k, T val) {
        sz=capa=k;
        arr = new T[k];
        for(int i=0; i<k; i++) arr[i]=val;
    }
    void resize(int k) {
        T *tmp;
        tmp = new T[k];
        for(int i=0; i<sz; i++) tmp[i]=arr[i];
        delete[] arr;
        arr=tmp;
        sz=capa=k;
    }

    int size() { return sz; }
    T* begin() const{ return &arr[0]; }
    T* end() const{ return &arr[0] + sz; }
    void push_back(T& val) {
        if(sz==capa) {
            resize(sz*2);
            sz/=2;
        }
        arr[sz++]=val;
    }
    void pop_back() {sz--;}
    T& operator [](int idx) { return arr[idx]; }
    T operator [](int idx) const { return arr[idx]; }
};
int main() {
    _vector<int> v(3,0);
    return 0;
}
