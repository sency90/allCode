#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int in[1000];
int n;

void cal(int start,int k,int ri,queue <int> pre,vector <int> post)
{
	
	if(pre.empty()) {return;}
	if(pre.size()==1)
	{
		for(int i=0; i<n; i++)
		{
			if(in[i]==0) {in[i]=pre.front();pre.pop(); return;}
		}
		
	}
	else{
	int root=pre.front();
	pre.pop();
	post.pop_back();
	int left;
	for(int i=start; i<k; i++)
	{
		if(pre.front()==post[i])
		{left=i;
		break;}
	}
	int rootindex=left+1+ri;
	in[rootindex]=root;
	queue <int> leftque;
	queue <int> rightque;
	vector <int> leftpost;
	for(int i=start; i<=left; i++)
	{
		leftque.push(pre.front());
		pre.pop();
	}

	for(int i=left+1; i<k; i++)
	{
		rightque.push(pre.front());
		pre.pop();
	}

	cal(start,left,0,leftque,post);
	cal(left+1,k-1,ri+1,rightque,post);
	return;
	}
}

int main()
{
	queue <int> pre;
	vector <int> post;

	scanf("%d",&n);

	int x;

	for(int i=0; i<n; i++)
	{
		scanf("%d",&x);
		pre.push(x);
	}

	for(int i=0; i<n; i++)
	{
		scanf("%d",&x);
		post.push_back(x);
	}

	cal(0,n-1,0,pre,post);

	for(int i=0; i<n; i++)
	{
		printf("%d ",in[i]);
	}

	return 0;

}