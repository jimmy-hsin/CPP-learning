#include <iostream>
using namespace std;

void swap(int x, int y);
void swapR(int &x, int &y);
int main()
{
    int a=10, b=20;
    //show the result comparison of functoion which swap using call by value
    cout<<"Swap with call by value"<<"\n";          
    cout<<"Before: "<<a<<","<<b<<"\n";
    swap(a,b);
    cout<<"After: "<<a<<","<<b<<"\n"<<"\n";

    //show the result comparison of functoion which swap using call by reference
    cout<<"Swap with call by reference"<<"\n";     
    cout<<"Before: "<<a<<","<<b<<"\n";
    swapR(a,b);
    cout<<"After: "<<a<<","<<b<<"\n";   
}
//swap by value
void swap(int x, int y)
{
    int temp= x;
    x=y;
    y=temp;
}
//swap by reference
void swapR(int &x, int &y)
{
    int temp=x;
    x=y;
    y=temp;
}