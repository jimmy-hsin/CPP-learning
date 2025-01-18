#include <iostream>
using namespace std;

int main()
{
    int n,m,s,t;
    cin>>n>>m>>t>>s;
    int count=0;
    for(int i=0;i<m;i++)
    {
        int sum=0;   
        for(int j=0;j<n;j++)
        {
            int x=0;
            cin>>x;
            if(x>=t)
                sum+=x;
        }
        if(sum>=s)
            count++;        
    }
    cout<<count;
}