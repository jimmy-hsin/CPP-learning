#include <iostream>
using namespace std;

int fun(int x)
{
   int count = 0 ;
   while(x){
      count++ ;
      x = x & (x-1) ;
   }
   return count ;
}
int main()
{
   int n=fun(456);
   cout<<n;
   int a=fun(456)+fun(123);
   cout<<a;
   int b=fun(456)+fun(123)+fun(789);
   cout<<b;
}

