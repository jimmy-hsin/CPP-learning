#include <iostream>
using namespace std;


int main()
{
    int c;
    cin>>c;
    if(c==1)
    {
        c=4;
        cout<<c<<" ";
    }
    while(c!=1)
    {
        if(c%2==1)
        {
            c=3*c+1;
            cout<<c<<" ";
        } 
        else
        {
            c=c/2;
            cout<<c<<" ";
        }
    }
}
