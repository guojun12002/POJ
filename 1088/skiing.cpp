#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int **space(int R, int C);
int next(int **M, int **f, int **L, int i, int j);
void modify(int **f, int i, int j);
int max(int **L, int R_, int C_);

int main()
{
    int R,C;
    freopen("input.txt","r",stdin);
    cin>>R>>C;
        int R_=R+2;
        int C_=C+2;
        int **Montain, **Line, **flag;
        Montain=space(R_,C_);
        Line=space(R_,C_);
        flag=space(R_,C_);
        for(int i=0; i<R_; i++)
        {
            for(int j=0; j<C_; j++)
            {
                if (i!=0 && j!=0 && i!=R_-1 && j!=C_-1)
                {
                    Line[i][j] = 1;
                    cin>>Montain[i][j];
                }
                else
                {
                    Montain[i][j] = 0;
                    Line[i][j] = 0;
                }
                flag[i][j] = 0;
            }
        }
on:
        for(int i=1; i<R_-1; i++)
        {
            for(int j=1; j<C_-1; j++)
            {
                int temp=next(Montain,flag,Line,i,j);
                if(Line[i][j]!=temp)
                {
                    Line[i][j]=temp;
                    goto on;
                }
            }
        }
        cout<<max(Line,R_,C_)<<endl;

        free(Montain);
        free(Line);
        free(flag);
}

int next(int **M, int **f, int **L, int i, int j)
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

int **space(int R, int C)
{
    int **M;
    M=(int **)malloc(sizeof(int*)*R);
    for(int i=0; i<C; i++)
    {
        M[i]=(int*)malloc(sizeof(int)*C);
    }
    return M;
}

void modify(int **f, int i, int j)
{
    if(f[i-1][j]==2) f[i-1][j]=0;
    if(f[i+1][j]==1) f[i+1][j]=0;
    if(f[i][j-1]==4) f[i][j-1]=0;
    if(f[i][j+1]==3) f[i][j+1]=0;
}

int max(int **L, int R_, int C_)
{
    int maxl=L[0][0];
    for(int i=1; i<R_-1; i++)
        for(int j=1; j<C_-1; j++)
            if(maxl<L[i][j]) maxl=L[i][j];
    return maxl;
}
