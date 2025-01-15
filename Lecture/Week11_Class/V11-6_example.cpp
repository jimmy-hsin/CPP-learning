#include <iostream>
using namespace std;

class A
{
public:
    A()
        {cout<<"AA\n";}
    ~A()
        {cout<<"aa\n";}
};

class B
{
private:
    A a;  //內建一個物件，型態為A，名稱為a
public:
    B()
        {cout<<"BB\n";}
    ~B()
        {cout<<"bb\n";}
};

int main()
{
    B b;//
    //1.B裡面第一行遇到A，所以先進行A的Constructor (印出AA)
    //2.運行B的constructor                       (印出BB)
    //3.B的block運行結束，運行destructor          (印出bb)
    //4.Class A隨著B結束，A的物件也被消滅          (印出aa) 
    return 0;
}