#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int r[n]; //每站車輛上限
    int x[n]; //每站車輛初始值
    for(int i=0;i<n;i++)
        cin>>r[i];
    for(int i=0;i<n;i++)
        cin>>x[i];
    
    for(int i=0;i<m;i++)
    {
        int b,e;//begin and end 
        cin>>b>>e;   
        if(x[b-1]!=0 & x[e-1]<r[e-1]) //點b有車借, 點e有位還
        {
            x[b-1]--;
            x[e-1]++;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(i==0)
            cout<<x[0];
        else
            cout<<","<<x[i];
    }
}
