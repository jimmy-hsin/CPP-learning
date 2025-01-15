#include <iostream>
using namespace std;

int main()
{
    int x,p1,p2,p3,y;
    cin>>x>>p1>>p2>>p3>>y;
    //買幾個蔥油餅
    if(x>=p1){
        x=x-p1;
        cout<<1<<",";}
    else
        cout<<0<<",";
    //買幾杯葡萄柚綠茶    
    if(x>=p2){
        x=x-p2;
        cout<<1<<",";}
    else
        cout<<0<<",";
    if(x>=p3*y)
        x=x-(p3*y);
    else{
        y=0;
        while(x>=p3) {
            x-=p3;
            y++; }}
    cout<<y<<","<<x;      
}