#include <iostream>
using namespace std;
/*
    1. this 是一個指標，指向的位址就是物件的記憶體位址，所以我們要取值的時候可以用->來取用member element
    2. 為什麼要用this, 因為以之前的例子來說，傳入值的名字一定不能跟自身member的名字重複，如果我們用this，就能區分自身的member與傳入值的區別
        邏輯上比較直觀，可讀性較好
  
*/

//----------------------Part 1--------------------
class A
{
  private:
    int a;
  public:
    void f() { cout << this << "\n"; }    
    A* g() { return this; }              
};
//--------------------------Part 2----------------------
class MyVector{
  private:
    int n;
    int* m;
  public:
    MyVector(); //default constructor
    MyVector(int dim,int v[]); //
    void print();
};

MyVector::MyVector(){
    n=0;
    m=nullptr;
}
//過去的寫法
MyVector::MyVector(int dim, int v[])
{
  n = dim;
  for(int i = 0; i < n; i++)
    m[i] = v[i];
}
//用this的寫法
//如果不用this的話，由於local variable (傳入值)的取名權限高於instance variable(物件的變數)，
//所以會變成local variable 對自己賦值(兩個n都是傳入值)，做無用功
//建議instance variable 都用this 好讓自己辨別
MyVector::MyVector(int n, int m[])
{
  this->n = n;
  for(int i = 0; i < n; i++)
    this->m[i] = m[i];
}

void MyVector::print() {
    cout << "(";
    for(int i = 0; i < n - 1; i++)
        cout << m[i] << ", ";
    cout << m[n-1] << ")\n";
}



int main()
{
    A obj;
    cout << &obj << "\n"; // 0x9ffe40
    obj.f(); // 0x9ffe40
    cout << (&obj == obj.g()) << "\n"; // 1
    return 0;
}
