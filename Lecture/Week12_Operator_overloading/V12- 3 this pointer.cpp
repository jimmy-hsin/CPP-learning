#include <iostream>
using namespace std;
/*
  this 是一個指標，指向的位址就是物件的記憶體位址
  所以我們要取值的時候可以用->來取用member element
*/
class A
{
  private:
    int a;
  public:
    void f() { cout << this << "\n"; }    
    A* g() { return this; }              
};

int main()
{
    A obj;
    cout << &obj << "\n"; // 0x9ffe40
    obj.f(); // 0x9ffe40
    cout << (&obj == obj.g()) << "\n"; // 1
    return 0;
}
