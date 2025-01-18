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
    if(d1==d2 and d2==d3)//d1==d2==d3
    {
        if(d1==a1 || d1==a2)        
            compare(n1,n2,n3);      
        else
            cout<<-1;
        
    }
    else if(d1==d3 and d2!=d3)//d1==d3 but d2 single
    {
        if((d1==a1 & d2==a2)||(d1==a2 & d2==a1))
            compare(n1,n2,n3);
        else if((d1==a1 & d2!=a2)||(d1==a2 & d2!=a1))
        {
            if(n1<n3)
                cout<<n1<<","<<n3;
            else
                cout<<n3<<","<<n1;
        }
            
        else if((d1!=a1 & d2==a2)||(d1!=a2 & d2==a1))
            cout<<n2;
        else
            cout<<-1;
    }
    else if(d3==d2 and d1!=d3)//d2==d3 but d1 single
    {
        if((d2==a1 & d1==a2)||(d2==a2 & d1==a1))
            compare(n1,n2,n3);
        else if((d2==a1 & d1!=a2)||(d2==a2 & d1!=a1))
        {
            if(n2<n3)
                cout<<n2<<","<<n3;
            else
                cout<<n3<<","<<n2;
        }        
        else if((d2!=a1 & d1==a2)||(d2!=a2 & d1==a1))
            cout<<n1;
        else
            cout<<-1;
    }
    else if(d1==d2 and d2!=d3)//d1==d2 but d3 single
    {
        if((d1==a1 & d3==a2)||(d1==a2 & d3==a1))
            compare(n1,n2,n3);
        else if((d1==a1 & d3!=a2)||(d1==a2 & d3!=a1))
        {
            if(n1<n2)
                cout<<n1<<","<<n2;
            else
                cout<<n2<<","<<n1;
        }
            
        else if((d1!=a1 & d3==a2)||(d1!=a2 & d3==a1))
            cout<<n3;
        else
            cout<<-1;
    }
    else//1
    {
        int c1=-1,c2=-1;
        if(a1==d1)
            c1=n1;
        if(a1==d2)
            c1=n2;
        if(a1==d3)
            c1=n3;
        if(a2==d1)
            c2=n1;
        if(a2==d2)
            c2=n2;
        if(a2==d3)
            c2=n3;
        if(c1==c2)
            cout<<c1;
        else if(c1<=c2 &c1!=-1)
            cout<<c1<<","<<c2; 
        else if(c2<=c1 &c2!=-1)
            cout<<c2<<","<<c1;
        else if(c1==-1)
            cout<<c2;
        else if(c2==-1)
            cout<<c1;
    }   
}