#include <iostream>
using namespace std;

int main()
{
    int m,k;
    cin>>m>>k;
    int n[m],d[m],a[k];
    //Data import
    for(int i=0;i<m;i++)
        cin>>n[i];
    for(int i=0;i<k;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>d[i];
    //Data Analysis
    int count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
            if(d[i]==a[j])
                count++;
    }
    cout<<count;
    /*int boo[m]={0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
            if(d[i]==a[j])
                boo[i]=1;
    }
    int count=0;
    for(int i=0;i<m;i++)
        if(boo[i]==1)
            count++;
    cout<<count;
    */
    
}
