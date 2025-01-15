#include <iostream>
using namespace std;

int main()
{
    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int m[6][6]={0};//array for judge
    
    for(int i=0;i<6;i++)
    {
        m[x1][i]=1; m[x2][i]=1; m[x3][i]=1; //same line
        m[i][y1]=1; m[i][y2]=1; m[i][y3]=1; //same row
        for(int j=0;j<6;j++)
        {
            int s=i+j;
            if(s==x1+y1 || s==x2+y2 || s==x3+y3)
                m[i][j]=1;

            s=i-j;
            if(s==x1-y1 || s==x2-y2 || s==x3-y3)
                m[i][j]=1;    
        }
    }

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(m[i][j]==0)
                cout<<i<<" "<<j<<endl;
        }
    }
}