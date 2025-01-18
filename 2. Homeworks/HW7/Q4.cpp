#include <iostream>
#include <cmath>
using namespace std;

void factorize(int n);
bool isPrime(int n);

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(isPrime(i))
            cout<<i;
        else
            factorize(i);   
        cout<<endl;
    }        
}

void factorize(int n)
{
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
bool isPrime(int n)
{
    bool yn=1;
    int x=sqrt(n);
    for(int i=2;i<=x;i++)
        if(n%i==0)
        {
            return false;
        }
    return yn;
}