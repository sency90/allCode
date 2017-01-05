#include<iostream>
using namespace std;
long A[1000][2] ={};
long D[1000] ={};
long C[1000][2] ={};
void CrearC(long K)
{
	for(int i=0;i<K;i++)
	{
		C[i][0]=0;
		C[i][1]=0;
	}
}
void Allexistence(long A)
{
	for(int i=0;i<A;i++)
	{
		for(int j=0;j<A;j++)
		{
			if(C[i][0] == D[j])
			{
				C[i][1] = 1;
			}
		}
	}
}
bool All_existence(long A)
{
	if(A==0)
	{
		return false;
	}
	else{
		for(int i=0;i<A;i++)
		{
			if(C[i][1] != 1)
			{
				return false;
			}
		}
	}
	return true;
}

void AllexistenceA(long B)
{
	for(int i=0;i<B;i++)
	{
		for(int j=0;j<B;j++)
		{
			if(A[i][0] == D[j])
			{
				A[i][1] = 1;
			}
		}
	}
	for(int i=0;i<B;i++)
		if(A[i][1]==0)
			D[B-1] =A[i][0];
}


int main()
{
	long B[1000]={};
	long a;
	long stack[1000] ={};
	int bam=0,sp=0;
	bool K=true;
	cin>>a;

	for(int i =0;i<a;i++)
		cin>>A[i][0];

	for(int i =0;i<a;i++)
		cin>>B[i];

	
	for(int i=0;i<a;i++)	
	{
		for(int j=0;j<a;j++)
		{
			if(A[i][0]!= B[j])
				C[j][0]= B[j];
			else if(A[i][0] == B[j])
			{
				stack[sp] = A[i][0];
				sp += 1;
				Allexistence(sp-1);
				K=All_existence(sp-1);
				if(C[0][0] == 0)
				{
					D[bam] = stack[sp-1];
					bam +=1;
					sp -=1;
					D[bam] = stack[sp-1];
					bam +=1;
					sp -=1;
				}
				else if(K)
				{
					D[bam] = stack[sp-1];
					bam +=1;
					sp -=1;
					D[bam] = stack[sp-1];
					bam +=1;
					sp -=1;
				}
				CrearC(a);
				break;
			}
		}
	}
	AllexistenceA(a);
	for(int i=0;i<a;i++)
		cout<<D[i];

}