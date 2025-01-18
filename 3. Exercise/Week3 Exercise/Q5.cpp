#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    //read data input
    int N=0,m=0;
    cin>>N>>m;
    int x[m]={0};
    for(int i=0;i<m;i++)
        cin>>x[i];
    
    const int nMax=10;
    float MAE[nMax]={0};
    //calculating MAE for each n
    for(int n=2;n<=N;n++)//setting n=what
    {
        float SAE=0;
        for(int j=n;j<m;j++) //SAE comparison
        {
            float sum=0;
            for(int k=0;k<n;k++)//summing up element for moving average
                sum+=x[n+k];
            float mav=sum/n;//calculating moving average
            SAE+=abs(x[j]-mav);
        }
        MAE[n-1]=SAE/(m-n);
    }
    //find the minimum MAE
    float bestMAE=100000000;
    int bestN=0;
    for(int i=1;i<N;i++)
    {
        if(MAE[i]<bestMAE)
        {
            bestMAE=MAE[i];
            bestN=i+1;
        }
    }
    bestMAE*=100;
    int xx=bestMAE;
    float bMAE=xx/100;
    cout<<bestN<<" "<<bMAE;
    
    return 0;
}