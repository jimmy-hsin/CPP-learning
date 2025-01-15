#include <iostream>
using namespace std;

int main()
{
    int n=0;
    cin>>n;
    int i=2;
    while(n>1)
    {
        int pow=0;
        while(n%i==0)
        {
            pow++;
            n/=i;   
        }       
        if(pow>1)
            cout<<i<<" ^ "<<pow;
        else if(pow==1)
            cout<<i;
        if(pow>0 & n>1)
            cout<<" * ";        
        i++;    
    }
}