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
    MyVector(); //default constructor
    MyVector(int dim,int value=0); //若只傳一個參數進來，第二個參數'value'的預設值為0
    void print();
};

MyVector::MyVector()
{
    n=0;
    m=nullptr;
}
MyVector::MyVector(int dim,int value)
{
    n=dim;
    m=new int[n];
    for(int i=0;i<n;i++)
        m[i]=value;
}
