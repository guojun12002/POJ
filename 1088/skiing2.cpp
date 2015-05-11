#include<stdio.h>
#include<stdlib.h>
int next(int M[][102], int f[][102], int L[][102], int i, int j);
void modify(int f[][102], int i, int j);
int max(int L[][102], int R_, int C_);

int main()
{
    int R,C;
    int Montain[102][102]={0},Line[102][102]={0},flag[102][102]={0};
    freopen("input.txt","r",stdin);
    scanf("%d %d",&R,&C);
    int R_=R+2;
    int C_=C+2;
    for(int i=1; i<R_-1; i++)
    {
        for(int j=1; j<C_-1; j++)
        {
            scanf("%d",&Montain[i][j]);
        }
    }
    int k=0;
    while(k==0)
    {
        k=1;
        for(int i=1; i<R_-1; i++)
        {
            for(int j=1; j<C_-1; j++)
            {
                int temp=next(Montain,flag,Line,i,j);
                if(Line[i][j]!=temp)
                {
                    Line[i][j]=temp;
                    k=0;
                }
            }
        }
    }
    printf("%d\n",max(Line,R_,C_));
}

int next(int M[][102], int f[][102], int L[][102], int i, int j)
{
    int maxl=L[i][j];
    if(M[i][j]>M[i-1][j] && f[i][j]!=1 && maxl<=L[i-1][j])
    {
        maxl=L[i-1][j]+1;
        f[i][j]=1;
        modify(f,i,j);
    }
    if(M[i][j]>M[i+1][j] && f[i][j]!=2 && maxl<=L[i+1][j])
    {
        maxl=L[i+1][j]+1;
        f[i][j]=2;
        modify(f,i,j);
    }
    if(M[i][j]>M[i][j-1] && f[i][j]!=3 && maxl<=L[i][j-1])
    {
        maxl=L[i][j-1]+1;
        f[i][j]=3;
        modify(f,i,j);
    }
    if(M[i][j]>M[i][j+1] && f[i][j]!=4 && maxl<=L[i][j+1])
    {
        maxl=L[i][j+1]+1;
        f[i][j]=4;
        modify(f,i,j);
    }
    return maxl;
}

void modify(int f[][102], int i, int j)
{
    if(f[i-1][j]==2) f[i-1][j]=0;
    if(f[i+1][j]==1) f[i+1][j]=0;
    if(f[i][j-1]==4) f[i][j-1]=0;
    if(f[i][j+1]==3) f[i][j+1]=0;
}

int max(int L[][102], int R_, int C_)
{
    int maxl=L[0][0];
    for(int i=1; i<R_-1; i++)
        for(int j=1; j<C_-1; j++)
            if(maxl<L[i][j]) maxl=L[i][j];
    return maxl;
}
