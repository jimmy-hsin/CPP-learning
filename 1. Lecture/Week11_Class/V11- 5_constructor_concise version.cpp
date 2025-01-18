#include <iostream>
using namespace std;

/*
    Constructor & destructor
    *1.Initializer 可以自動被呼叫
    *2.動態配置的記憶體會自動被釋出

    Constructor: 是一種instance function
    會在object被建立的時候就自動被呼叫
        1.一定會被呼叫
        2.只能被呼叫一次
        3.不能被手動呼叫
    所以通常被用來對物件初始化
    因為太特別了，所以要給他一個特別的名字:跟class的名字一樣
    Constructor 不會回傳任何東西，且不用特別寫void
    Constructor可以且通常會使用overloading
    不傳入任何parameter的Constructor稱為default Constructor

*/

class MyVector
{
private:
    int n;
    int* m;
public:
    MyVector(int dim=0,int value=0); //若沒傳參數，兩個都預設0，隨著傳入參數數量，逐步更改預設值
    void print();
};

MyVector::MyVector(int dim,int value)
{
    if(dim==0){
      n=0;
      m=nullptr;
    }
    else{
      n=dim;
      m=new int[n];
      for(int i=0;i<n;i++)
          m[i]=value;
    }
}
void MyVector::print(){
    if (n == 0) {
        std::cout << "Empty vector!" << std::endl;
    }
    else{
      cout<<"(";
      for(int i=0;i<n-1;i++)
          cout<<m[i]<<", ";
      cout<<m[n-1]<<")";
    }
}
