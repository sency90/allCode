#include <cstdio>
using namespace std;
int ps[5010];
int main() {
	int n; scanf("%d",&n);
	fflush(stdout);
	printf("? 1 2\n\n"); fflush(stdout); scanf("%d",&ps[0]);
	printf("? 1 3\n\n"); fflush(stdout); scanf("%d",&ps[1]);
	printf("? 2 3\n\n"); fflush(stdout); scanf("%d",&ps[2]);
	int s2,s3,s1 = (ps[0]+ps[1]-ps[2])/2;
	s2=(ps[0]+ps[2]-ps[1])/2;
	s3=(ps[1]+ps[2]-ps[0])/2;
	ps[0]=s1; ps[1]=s2; ps[2]=s3;
	int x;
	fflush(stdout);
	for(int i=4; i<=n; i++) {
		printf("? %d %d\n\n",1,i);
		fflush(stdout);
		scanf("%d",&x);
		ps[i-1]=x-ps[0];
	}
	printf("!");
	fflush(stdout);
	for(int i=0; i<n; i++) {
		printf(" %d",ps[i]);
		fflush(stdout);
	}
	fflush(stdout);
	return 0;
}
