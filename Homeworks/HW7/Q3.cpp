#include <iostream>
#include <cmath>
using namespace std;



int main()
{
    int n,m,p,c;
    cin>>n>>m>>p>>c;
    int uv[n][2]={0};
    for(int j=0;j<n;j++)
        for(int i=0;i<2;i++)
            cin>>uv[j][i];

    int store[m][3]={0};
    
    for(int j=0;j<m;j++)
        for(int i=0;i<2;i++)
            cin>>store[j][i];
    for(int j=0;j<m;j++)
        cin>>store[j][2];

    int cost[m]={0};

    for(int i=0;i<m;i++)
    {
        int templength=10000;
        for(int j=0;j<n;j++)
        {
            int distance=abs(store[i][0]-uv[j][0])+abs(store[i][1]-uv[j][1]);
            if(j==0 || distance<templength)
                templength=distance;
        }
        cost[i]=templength*c;
    }
    int unmet=0;
    int costAll=0;
    for(int i=0;i<m;i++)
    {
        if(cost[i]>p)
            unmet+=store[i][2];
        else
            costAll+= ( (p-cost[i])*store[i][2]   );
    }

    cout<<costAll<<","<<unmet;

}