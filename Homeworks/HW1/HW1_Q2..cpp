#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<1;
    for(int i=1;i<(n/m);i++)
    {
        cout<<","<<m*i+1;
    }
        
}

