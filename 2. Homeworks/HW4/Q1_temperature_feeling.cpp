#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int ts[n][2]; //temp, speed
    for(int i=0; i<n;i++)
        cin>>ts[i][0]>>ts[i][1];
    int temp=ts[0][0];
    int speed=ts[0][1];
    int c=0;
    for(int i=1;i<n;i++)
    {
        double sp_dg=sqrt(speed);
        double dg=sqrt(ts[i][1]);

        double A=temp+2*dg;
        double B=ts[i][0]+2*sp_dg;
        if(B<A)
        {
            c=i;
            temp=ts[i][0];
            speed=ts[i][1];
        }
    }
    cout<<c+1;
}