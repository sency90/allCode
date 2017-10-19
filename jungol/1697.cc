#include <stdio.h>
char str[2];
struct Queue{
	int v[11000];
	int r,f;
	Queue():r(0),f(0){}
	inline void push(int x) { v[f++]=x; }
	inline int pop() { return v[r++]; }
	inline bool empty() { return r==f; }
	inline int size() { return f-r; }
};
Queue q;
int main() {
	int n; scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%s",str);
		if(str[0]=='i') {
			int val; scanf("%d",&val);
			q.push(val);
		} else if(str[0]=='c') printf("%d\n",q.size());
		else {
			if(!q.empty()) printf("%d\n",q.pop());
			else puts("empty");
		}
	}
	return 0;
}
