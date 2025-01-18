#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<1;
    if(n/m>0){
        for(int i=1;i<(n/m);i++)
            cout<<","<<m*i+1;
        if(n%m>0)
            cout<<","<<n-(n%m)+1;
    }          
}

