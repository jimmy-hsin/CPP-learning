#include <iostream>
using namespace std;

int main()
{
    int q,n;
    cin>>n>>q;
    int p[n];
    int x[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        cin>>x[i];

    for(int i=0;i<n;i++)
    {
        if((x[i]==1 & q>=p[i]) || (x[i]==0 & q>=p[i]*2))
            q=q-p[i];
        if(i==0)
            cout<<q;
        else
            cout<<","<<q;
    }    
}