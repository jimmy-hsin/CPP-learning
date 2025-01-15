#include <iostream>
using namespace std;

int main()
{
    /*
    int a=10;
    int *ptr=&a;
    cout<<&*ptr<<",";
    cout<<*&a;
    */
   int a[]={1,2,5};
   int *x = &a[0];
   int y=&a[2]-&a[0];
   cout<<*(x+2)<<" "<<y<<"\n";
   x+=2;
   cout<<*x;

}