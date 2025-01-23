#include <iostream>
#include "myMax.h"
using namespace std;

/*
  要把自己的class變成一個self define library要先做以下事情
  1. 把除了之前寫class時，member function的實作方式儲存進myClass.cpp( source file )裡，include header file 的檔名/位置
  2. 創建一個header file: myClass.h, 其中包含所有class中的 member variable 和 member function 的definition寫進去，
  3. 將以上兩個檔案一起compile
*/


int main() 
{
  int a[LEN] = {7, 2, 5, 8, 9};
  print(myMax(a, LEN));
  return 0;
}

