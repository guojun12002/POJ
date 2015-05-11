#include<stdio.h>
#include<math.h>

int main()
{
    freopen("input.txt","r",stdin);
    int a, b;
    double p= (1.0+sqrt(5.0))/2.0;
    while(scanf("%d%d", &a, &b)!=EOF)
    {
        if(a>b)
        {
            int c=a;
            a=b;
            b=c;
        }
        int c= b-a;
        if(a==(int)(c*p)) printf("0\n");
        else printf("1\n");
    }
}
