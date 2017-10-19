#include <stdio.h>
void swap(int &x,int &y) {
	x^=y; y^=x; x^=y;
}
inline int max(int x,int y) { return x>y?x:y; }
struct Heap{
	int v[500001],sz=0;
	void push(int x) {
		v[++sz] = x;
		int p = sz>>1;
		if(p==0) return;
		else {
			int cur = sz;
			while(cur!=1) {
				if(v[p]<v[cur]) swap(v[cur],v[p]);
				else break;
				cur = p;
				p = cur>>1;
			}
		}
	}
	int pop() {
		int tmp = v[1];
		v[1]=v[sz--];
		int cur = 1;
		while(cur<=sz) {
			int l=cur*2,r=cur*2+1;
			int t = v[cur], tc=cur;
			if(l<=sz && t<v[l]) t=v[l], tc=l;
			if(r<=sz && t<v[r]) t=v[r], tc=r;
			if(t!=v[cur]) swap(v[cur],v[tc]);
			else break;

			cur = tc;
		}

		return tmp;
	}
	int size() { return sz; }
	bool empty() { return sz<=0; }
	void print() {
		for(int i=1; i<=sz; i++) printf("%d ",v[i]);
	}
};
Heap h;
int v[500001];
int main() {
	int n; scanf("%d",&n);
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d",&x);
		h.push(x);
	}
	h.print(); puts("");
	int j=h.size()-1, z=h.size();
	while(!h.empty()) v[j--]=h.pop();
	for(int i=0; i<z; i++) printf("%d ",v[i]);
	return 0;
}
