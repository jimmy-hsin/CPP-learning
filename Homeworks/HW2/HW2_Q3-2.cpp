#include <iostream>
using namespace std;

int main()
{
    int n1,n2,n3,d1,d2,d3,a1,a2;
    cin>>n1>>n2>>n3>>d1>>d2>>d3>>a1>>a2;
    int y[3]={0, 0, 0}; //matching array
    int i=0;            //match count

    //matching Analysis
    if(d1==a1 || d1==a2)
    {   y[0]=n1;
        i++;       }
    if(d2==a1 || d2==a2)
    {   y[1]=n2;
        i++;       }
    if(d3==a1 || d3==a2)
    {   y[2]=n3;
        i++;       }

    if(i==0)
        cout<<-1;
    else
    {   
        int ii,j,temp;    //variable for sorting
        for(j=2;j>0;j--)                   //bubble sorting
        {   for(ii=0;ii<=j-1;ii++)
                if(y[ii]>y[ii+1])
                {   temp=y[ii];
                    y[ii]=y[ii+1];
                    y[ii+1]=temp;     }}
        
        if(i==1)
            cout<<y[2];
        if(i==2)
            cout<<y[1]<<","<<y[2];
        if(i==3)
            cout<<y[0]<<","<<y[1]<<","<<y[2];
    }   
}