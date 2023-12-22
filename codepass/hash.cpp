#include <stdio.h>
template <typename T>
struct Vector{
	T *v;
	int idx,sz;
	Vector():v(NULL),idx(0),sz(0) {}
	virtual ~Vector() {
		if(v) { free(v); v=NULL; }
	}
};
template <typename Key, Value>
struct HashMap{
	Vector<pair<Key,Value>> v;
};
unordered_map<string, int> hmap;
hmap.emplace("string", Value()); //string이 hashing되어 저장되도록 하자.
hmap.count("string") 이렇게 하면 Value로 지정한 값이 나오도록 하는거 return Value
int main() {
	return 0;
}
