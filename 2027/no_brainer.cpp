#include<stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    int n, num1, num2;
    scanf("%d",&n);
    bool *num = new bool[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &num1, &num2);
        num[i]=num1>=num2?true:false;
    }
    for(int i=0; i<n; i++)
    {
        if(num[i])
            printf("MMM BRAINS\n");
        else
            printf("NO BRAINS\n");
    }
    delete []num;
}
