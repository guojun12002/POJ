#include <stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	double num;
	double sum=0;
	int i=0;
	while(scanf("%lf",&num)!=EOF)
	{
		i++;
		sum+=num;
		if(i%12==0)
		{
			printf("$%.2f\n", sum/12);
			sum=0;
		}
	}
	return 0;
}