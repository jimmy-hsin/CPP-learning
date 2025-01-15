#include <iostream>
using namespace std;

int main()
{
    int y;
    bool L=0;
    cin>>y;
    if(y%4==0)
    {
        L=1;
        if(y%100==0 & y%400!=0)
            L=0;
    }
    cout<<L;
}