#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,same =0;
	int X[1000]={};
	int count[1000][2] ={};

	cin>> n;
	for(int i=0;i<n;i++)
		cin>>X[i];

	sort(X,X+n);

	for(int i=n;i>=0;i--)
	{
		if(X[i+1]==0)
		{
			if(X[i] != 0)
				count[i][0] +=1;
			if(X[i]==0)
			{
				count[i][0]=0;
			}
		}
		else if(X[i+1] !=0){
			if(X[i] == X[i+1]){
				count[i][0]=count[i+1][0]=count[i+1][0]+1;
				same +=1;
			}
			else if(X[i]<X[i+1])
				count[i][0]=count[i+1][0]+1;
			}
	}
	for(int i=0;i<n;i++)
	{
		if(X[i]<=count[i][0])
			count[i][1]= 1;						
	}
	for(int i=n;i>=0;i--)
	{
		if(count[i][1] !=0)
		{
			n=X[i];break;
		}
		else
			n=0;
	}
	cout<<n;
}