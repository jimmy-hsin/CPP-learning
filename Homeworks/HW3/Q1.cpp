#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin>>n>>t;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    int sum=0;
    int count=0;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(x[i]>=t)
        {
            sum+=x[i];
            count++;
        }
        if(x[i]>temp)
            temp=x[i];
    }
    if(sum==0)
        sum=-1;
    else
        sum=sum/count;
    cout<<temp<<","<<sum;   
}