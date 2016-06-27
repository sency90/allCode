#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;
int a[1001];
int d[1001];
int  mx=1;
int f(int n){
	if(n==1) return 1;
	if(d[n]>0) return d[n];

    int tmp=0;
	for(int i = n-1; i >= 1; i-- ){
		if(a[i] < a[n]) {
            tmp = max(tmp, f(i));
		} else f(i);
	}
	d[n] = tmp+1;
	mx = max(mx, d[n]);
	return d[n];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	f(n);
	printf("%d", mx);
	return 0;
}
