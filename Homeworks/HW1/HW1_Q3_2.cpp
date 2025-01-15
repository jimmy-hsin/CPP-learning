#include <iostream>
using namespace std;

void compare(int n1,int n2,int n3)
{
    if(n1<n2 & n2<n3)
        cout<<n1<<","<<n2<<","<<n3;
    if(n1<n3 & n3<n2)
        cout<<n1<<","<<n3<<","<<n2;
    if(n2<n1 & n1<n3)
        cout<<n2<<","<<n1<<","<<n3;
    if(n2<n3 & n3<n1)
        cout<<n2<<","<<n3<<","<<n1;
    if(n3<n1 & n1<n2)
        cout<<n3<<","<<n1<<","<<n2;
    if(n3<n2 & n2<n1)
        cout<<n3<<","<<n2<<","<<n1;
}

int main()
{
    int n1,n2,n3,d1,d2,d3,a1,a2;
    cin>>n1>>n2>>n3>>d1>>d2>>d3>>a1>>a2;
    bool c1=0,c2=0,c3=0;
    if(d1==a1 || d1==a2)
        c1=1;
    if(d2==a1 || d2==a2)
        c2=1;
    if(d3==a1 || d3==a2)
        c3=1;

    if(c1==1 & c2==1 & c3==1)
        compare(n1,n2,n3);
    if(c1==1 & c2==1 & c3==0)
    {
        if(n1<n2)
            cout<<n1<<","<<n2;
        else
            cout<<n2<<","<<n3;        
    }
    if(c1==1 & c2==0 & c3==1)
    {
        if(n1<n3)
            cout<<n1<<","<<n3;
        else
            cout<<n3<<","<<n1;        
    }
    if(c1==0 & c2==1 & c3==1)
    {
        if(n2<n3)
            cout<<n2<<","<<n3;
        else
            cout<<n3<<","<<n2;        
    }
    if(c1==1 & c2==0 & c3==0)
        cout<<n1; 
    if(c1==0 & c2==1 & c3==0)
        cout<<n2; 
    if(c1==0 & c2==0 & c3==1)
        cout<<n3; 
    if(c1==0 & c2==0 & c3==0)
        cout<<-1;
}