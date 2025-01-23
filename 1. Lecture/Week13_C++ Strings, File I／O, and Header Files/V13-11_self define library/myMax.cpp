#include <iostream>
#include "myMax.h" //如果function 需要用到一些預設的變數的話，要記得把header file 引入，他才知道這些預設值
using namespace std; 

int myMax(int a[], int len)
{
  int max = a[0];
  for(int i = 1; i < len; i++)
  {
    if(a[i] > max)
      max = a[i];
  }
  return max;
}
void print(int i)
{
  cout << i; // cout undefined!
}

