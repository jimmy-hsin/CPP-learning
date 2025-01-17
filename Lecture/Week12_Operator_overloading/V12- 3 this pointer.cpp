#include <iostream>
using namespace std;

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
