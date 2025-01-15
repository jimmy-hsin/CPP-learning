#include <iostream>
#include <cmath>
using namespace std;

int has(int* row,int up,int down,int n)
{
    int boo=0;
    for(int i=up;i<down;i++)
    {
        if(*(row+1)>=n)
            boo=1;
    }
    return boo;
}

int main()
{
    int a[]={2,2,3,2,2,1,1};
    int pos[3][7]={{1,1,1,0,3,3,3},
                 {0,0,2,2,2,0,0},
                 {4,4,4,4,0,0,0}};
    int y=has(&a[0],3,7,3);
    int num=6;
    int start=3;
    int end=7;
    int n=4;
    if(y==0)
    {
        for(int t=start;t<end;t++)//處理第j個區段  
        {   
            for(int z=0;z<n-1;z++)//排進第z個位置
            {
                if(pos[z][t]==0)
                {
                    pos[z][t]=num;
                    pos[n-1][t]+=1;
                    break;
                }
            }
        }  
    }

    cout<<y;
}