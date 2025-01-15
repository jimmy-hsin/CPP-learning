#include <iostream>
using namespace std;

int main()
{
    int n,l;
    cin>>n>>l;   
    int x[l];
    for(int i=0;i<l;i++)
        cin>>x[i];

    int h=l-n+1;
    for(int i=0;i<h;i++)
    {
        int a=0;
        for(int j=0;j<n;j++)  
                a+=x[i+j];
        if(i==0)
            cout<<a/n;
        else
            cout<<","<<a/n;
    }
}
