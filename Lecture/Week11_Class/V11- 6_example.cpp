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
    //1.成員變數的construct 先於 自身類別的construct              (印出AA)
    //2.運行B的constructor                                      (印出BB)
    //3.B的block運行結束，運行destructor                         (印出bb)
    //4.在解構過程中，成員變數的 destructor會後於類別的 destructor (印出aa) 
    return 0;
}
