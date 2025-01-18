#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int mini(int a,int b);

int main()
{
    int w_h,t_h,w_l,t_l,W,T,p_h,p_l;
    cin>>W>>T>>w_h>>w_l>>t_h>>t_l>>p_h>>p_l;
    int profit=0;
    int maxH=min(W/w_h,T/t_h);  //H 最多能做幾個
    
    for(int i=0;i<=maxH;i++)
    {
        int tempprofit;
        int tempW=W-w_h*i;
        int tempT=T-t_h*i;
        int num_L=mini(tempW/w_l,tempT/t_l);
        tempprofit=i*p_h+num_L*p_l;
        if(tempprofit>profit)
            profit=tempprofit;    
    }
    cout<<profit<< '\n';
}

int mini(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;  
}