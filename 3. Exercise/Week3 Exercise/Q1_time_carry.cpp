#include <iostream>
using namespace std;

int main()
{
    int h,m,s,x;
    cin>>h>>m>>s>>x;
    s=s+x%60;
    if(s>=60)
    {   s-=60;
        x=x/60+1;   }
    else
        x=x/60;

    m=m+x%60;
    if(m>=60)
    {   m-=60;
        x=x/60+1;  }
    else
        x=x/60;
        
    h=h+x;
    if(h>24)
        h-=24;
    cout<<h<<":"<<m<<":"<<s;
}