#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int compare(const void* e1,const void* e2)
{
	int n1=*(int*)e1;
	int n2=*(int*)e2;
	return n2-n1;
}

int main()
{
	freopen("input.txt","r",stdin);
	// freopen("output.txt","r",stdout);
	int n;
	while(true)
	{
		cin>>n;
		if(n==0) break;
		int sum=0;
		int* stick= new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>stick[i];
			sum+=stick[i];
		}
		qsort(stick,n,sizeof(int),compare);
		int max=stick[0];
		int min=stick[n-1];
		
		delete []stick;
	}
	return 0;
}