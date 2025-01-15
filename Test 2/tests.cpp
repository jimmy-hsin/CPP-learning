#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isPrime(int n);

int main()
{
    cout<<isPrime(9);
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