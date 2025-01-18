#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int w[n],v[n],b[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
        
    int W_all=0;
    int V_all=0;
    for(int i=0;i<n;i++)
    {   W_all+=w[i]*b[i];
        V_all+=v[i]*b[i];   }

    if(W_all<=m)
        cout<<W_all<<" "<<V_all;
    else
        cout<<0;
}