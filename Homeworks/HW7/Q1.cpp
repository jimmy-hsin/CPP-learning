#include <iostream>
using namespace std;

int main()
{
    //Data input
    int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];

    //bubble sorting
    int swapC=0;
    int round=0; 
    for(int j=0;j<n-1;j++)
    {
        bool swap=0;
        round++;
               
        for(int i=0;i<n-j-1;i++)
            if(x[i]>x[i+1])
            {   swap=1;   
                int temp=x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
                swapC++;            }
        if(swap==0)
            break;
    } 

    cout<<swapC<<","<<round<<'\n';         
}

