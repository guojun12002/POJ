#include<stdio.h>
#include<stdlib.h>

int Montain[105][105]={}, Line[105][105]={};
int R,C;

int next(int i, int j);
int max(int num1, int num2);

int main()
{
    freopen("input.txt","r",stdin);
    scanf("%d %d", &R, &C);
    R=R+2; C=C+2;
    for(int i=1; i<R-1; i++)
    {
        for(int j=1; j<C-1; j++)
        {
            scanf("%d",&Montain[i][j]);
            Line[i][j]=1;
        }
    }

    for(int i=1; i<R-1; i++)
    {
        for(int j=1; j<C-1; j++)
        {
            Line[i][j]=next(i,j);
        }
    }

    int maxl=0;
    for(int i=1; i<R-1; i++)
    {
        for(int j=1; j<C-1; j++)
        {
            if(maxl<Line[i][j])
                maxl=Line[i][j];
        }
    }

    printf("%d\n",maxl);

}

int next(int i, int j)
{
    if(Line[i][j]>1) return Line[i][j];
    int maxl=Line[i][j];
    if(i>0 && i<R-1 && j>0 && j<C-1)
    {
        if(Montain[i][j]>Montain[i-1][j])
        {
            maxl=max(maxl,next(i-1,j)+1);
        }
        if(Montain[i][j]>Montain[i+1][j])
        {
            maxl=max(maxl,next(i+1,j)+1);
        }
        if(Montain[i][j]>Montain[i][j-1])
        {
            maxl=max(maxl,next(i,j-1)+1);
        }
        if(Montain[i][j]>Montain[i][j+1])
        {
            maxl=max(maxl,next(i,j+1)+1);
        }
    }
    Line[i][j]=maxl;
    return maxl;
}

int max(int num1, int num2)
{
    return (num1>num2)?num1:num2;
}
