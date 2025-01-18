#include <iostream>
using namespace std;


int main()
{
    int a, b, c, p;
    cin>>a>>b>>c;
    int optPrice=0;
    int optProfit=0;
    for(p=c+1;p<=a/b;p++)
    {
        int profit=(p-c)*(a-b*p);
        if(profit>optProfit)
        {
            optProfit=profit;
            optPrice=p;
        }
    }
    cout<<optPrice<<" "<<optProfit;
}