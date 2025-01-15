#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int mini(int a,int b);

int main()
{
    int n,W,T;
    cin>>n>>W>>T;

    int w[n],t[n],p[n];
    for(int i=n-1;i>=0;i--)
        cin>>w[i];
    for(int i=n-1;i>=0;i--)
        cin>>t[i];
    for(int i=n-1;i>=0;i--)
        cin>>p[i];
    
    int tempPro,tempW,tempT,tempAmount,maxProfit=-1;
    for(int i=0 ; i*w[n-1] <= W & i*t[n-1] <= T;i++)   //從做最高級(N)的碳開始往下算
    {
        //計算當做了i個N級碳時，W,T,Profit的值
        tempW= W - i*w[n-1];
        tempT= T - i*t[n-1];
        tempPro=i*p[n-1];
        for(int j=n-2 ; j>=0 ; j--)   //材料有剩的話，一直往低一級的碳做
        {
            if(tempW/w[j] && tempT/t[j])  //如果做得成的話
            {
                tempAmount=mini(tempW/w[j],tempT/t[j]);//j級碳最多能做多少個
                
                tempPro+=tempAmount*p[j];
                tempW-=tempAmount*w[j];
                tempT-=tempAmount*t[j];
            }
        }
        maxProfit=max(tempPro,maxProfit);
    } 
    cout<<maxProfit<<"\n";  
    return 0;
}

int mini(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;  
}