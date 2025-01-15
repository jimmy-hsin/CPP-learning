#include <iostream>
using namespace std;

int fibo(int n)
{
    if(n==1)
        return 1;
    else if (n==2)
        return 1;
    else
    {
        return (fibo(n-2)+fibo(n-1));
    }
    
}
int main()
{
    int a=fibo(30);
    cout<< a;
}