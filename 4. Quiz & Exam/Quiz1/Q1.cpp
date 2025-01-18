#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        if(a>0)
            cout<<a+b;
        else
            cout<<a*b;
        
    }
    else
        cout<<a-b;
    
}