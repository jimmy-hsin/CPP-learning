#include <iostream>
using namespace std;

int min(int a, int b)
{
    return a<b ? a:b;
}

int gcd(int a, int b)
{
    int mini=min(a,b);
    int r= min(mini,abs(a-b));

    int gcd=1;
    for(int i=1;i<=r;i++)
    {
        if(r%i==0)
        {
            gcd=r/i;
            if(a%gcd==0 & b%gcd==0)
                return gcd;
        }
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}