#include<stdio.h>
#define int64_t long long
int64_t x, y, m, n, L;
int64_t x0, y0;
int64_t extend_gcd(int64_t a, int64_t b);
int main()
{
    freopen("input.txt", "r", stdin);
    while(scanf("%d%d%d%d%d", &x, &y, &m, &n, &L)!=EOF)
    {
        int64_t c=x-y;
        int64_t d=extend_gcd(n-m, L);
        int64_t r=L/d;
        if(c%d!=0)
            printf("Impossible\n");
        else
            printf("%d", ((x0*c/d)%r+r)%r);
    }
}

int64_t extend_gcd(int64_t a, int64_t b)
{
    if(b==0)
    {
        x0=1;
        y0=0;
        return a;
    }
    int64_t d=extend_gcd(b, a%b);
    int64_t temp=x0-a/b*y0;
    x0=y0;
    y0=temp;
    return d;
}
